/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:35 by lrio              #+#    #+#             */
/*   Updated: 2024/01/05 10:13:23 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "colorset.h"
#include "threads.h"

t_fractal	calc_coord(t_fractal init_v)
{
	t_fractal	info;

	info.comp.max.imag = init_v.y + (init_v.comp.max.imag * init_v.zoom_factor);
	info.comp.max.real = init_v.x + (init_v.comp.max.real * init_v.zoom_factor);
	info.comp.min.imag = init_v.y + (init_v.comp.min.imag * init_v.zoom_factor);
	info.comp.min.real = init_v.x + (init_v.comp.min.real * init_v.zoom_factor);
	return (info);
}

int	make_pixel(t_engine *vars, t_complex z, t_complex c, t_pixel pixel)
{
	int					i;
	const t_colorset	color_tab[] = \
		{&colorset_one, &colorset_two, &colorset_three, &colorset_four};

	if (!(vars->fractal.settings.colorset >= 1 \
	&& vars->fractal.settings.colorset <= 4))
		vars->fractal.settings.colorset = 1;
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

void	*fast_draw(void *engine)
{
	t_pixel		pixel;
	t_engine	*vars;

	vars = (t_engine *)engine;
	pthread_mutex_lock(&vars->mutex_line_counter);
	while (vars->line_counter < W_H)
	{
		pixel.x = 0;
		pixel.y = vars->line_counter;
		vars->line_counter++;
		pthread_mutex_unlock(&vars->mutex_line_counter);
		draw_half_line(pixel.y, vars);
		pthread_mutex_lock(&vars->mutex_line_counter);
	}
	pthread_mutex_unlock(&vars->mutex_line_counter);
	return (NULL);
}

void	*draw_fractal(void *engine)
{
	t_pixel		pixel;
	t_engine	*vars;

	vars = (t_engine *)engine;
	pthread_mutex_lock(&vars->mutex_line_counter);
	while (vars->line_counter < W_H)
	{
		pixel.x = 0;
		pixel.y = vars->line_counter;
		vars->line_counter++;
		pthread_mutex_unlock(&vars->mutex_line_counter);
		draw_line(pixel.y, vars);
		pthread_mutex_lock(&vars->mutex_line_counter);
	}
	pthread_mutex_unlock(&vars->mutex_line_counter);
	return (NULL);
}
