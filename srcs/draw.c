/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:35 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 14:29:04 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"
#include "colorset.h"
#include <pthread.h>
#include "threads.h"

static t_fractal	calc_coord(t_fractal init_v)
{
	t_fractal	info;

	info.comp.max.imag = init_v.y + (init_v.comp.max.imag * init_v.zoom_factor);
	info.comp.max.real = init_v.x + (init_v.comp.max.real * init_v.zoom_factor);
	info.comp.min.imag = init_v.y + (init_v.comp.min.imag * init_v.zoom_factor);
	info.comp.min.real = init_v.x + (init_v.comp.min.real * init_v.zoom_factor);
	return (info);
}

static int	make_pixel(t_engine *vars, t_complex z, t_complex c, t_pixel pixel)
{
	int					i;
	const t_colorset	color_tab[] = \
		{&colorset_one, &colorset_two, &colorset_three, &colorset_four};

	i = 0;
	pixel.iterations = vars->fractal.fractal_func(z, c, vars->fractal.max_iter);
	if (pixel.iterations > vars->fractal.max_iter - 1 \
	&& vars->fractal.settings.d_color == 1)
		return (0);
	while (i != vars->fractal.settings.colorset && i <= 4)
		i++;
	return (color_tab[i - 1](pixel));
}

t_complex	getcomplex(t_pixel pixel, t_fractal info)
{
	t_complex	c;

	c.real = info.comp.min.real + \
				(info.comp.max.real - info.comp.min.real) * pixel.x / W_W;
	c.imag = info.comp.min.imag + \
				(info.comp.max.imag - info.comp.min.imag) * pixel.y / W_H;
	return (c);
}

void	fast_draw(t_engine *vars)
{
	t_pixel		pixel;
	void		*img_ptr;

	img_ptr = vars->img.addr;
	pixel.y = 0;
	while (pixel.y < W_H)
	{
		pixel.x = 0;
		while (pixel.x < W_W)
		{
			if (!(pixel.x % 2 == 1 || pixel.y % 2 == 1))
				*(uint32_t *)img_ptr = make_pixel(vars, vars->fractal.z, \
					getcomplex(pixel, calc_coord(vars->fractal)), pixel);
			else
				*(uint32_t *)img_ptr = 1;
			img_ptr = (uint8_t *)img_ptr + (vars->img.bits_per_pixel / 8);
			pixel.x++;
		}
		pixel.y++;
	}
	odd_pixel((uint32_t *)vars->img.addr);
	even_pixel((uint32_t *)vars->img.addr);
	vars->fractal.needredraw = 0;
}

int	inti_thread(void *(*start_routine) (void *), void *args)
{
	pthread_t	threads[NB_THREADS];
	int			i;
	t_engine	*engine;

	engine = (t_engine *)args;
	i = 0;
	engine->line_counter = 0;
	while (i != NB_THREADS)
	{
		if(-1 == pthread_create(threads + i, NULL, start_routine, args)) {
			// TODO : * CLOSE LES THREADS PRECEDENT
			return -(1);
		}
		i++;
	}
	i = 0;
	while (i != NB_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	engine->fractal.needredraw = 0;
	return (1);
}

void	*draw_fractal(void *engine)
{
	t_pixel		pixel;
	void		*img_ptr;
	t_engine	*vars = engine;
	uint32_t 	buffer_line[W_W];
	uint32_t	i;

	pthread_mutex_lock(&vars->mutex_line_counter);
	pixel.y = vars->line_counter;
	pthread_mutex_unlock(&vars->mutex_line_counter);
	while (pixel.y < W_H)
	{
		i = 0;
		pixel.x = 0;
		pthread_mutex_lock(&vars->mutex_line_counter);
		vars->line_counter++;
		pthread_mutex_unlock(&vars->mutex_line_counter);
		while (pixel.x < W_W)
		{
			buffer_line[i] = make_pixel(vars, vars->fractal.z, \
						getcomplex(pixel, calc_coord(vars->fractal)), pixel);
			i++;
			pixel.x++;
		}
		pthread_mutex_lock(&vars->mutex_img);
		img_ptr = vars->img.addr + W_W * pixel.y * (vars->img.bits_per_pixel / 8);
		for (int y = 0; y < W_W - 1; y++) {
			*(uint32_t *)img_ptr = buffer_line[y];
			img_ptr = (uint8_t *)img_ptr + (vars->img.bits_per_pixel / 8);
		}
		pthread_mutex_unlock(&vars->mutex_img);

		pthread_mutex_lock(&vars->mutex_line_counter);
		pixel.y = vars->line_counter;
		pthread_mutex_unlock(&vars->mutex_line_counter);
	}
	return (NULL);
}
