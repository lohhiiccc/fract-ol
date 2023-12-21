/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:35 by lrio              #+#    #+#             */
/*   Updated: 2023/12/21 14:25:00 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

static t_info	calc_coord(t_info initv)
{
	t_info	info;

	info.comp.max.imag = initv.y + (initv.comp.max.imag / initv.zoom_factor);
	info.comp.max.real = initv.x + (initv.comp.max.real / initv.zoom_factor);
	info.comp.min.imag = initv.y + (initv.comp.min.imag / initv.zoom_factor);
	info.comp.min.real = initv.x + (initv.comp.min.real / initv.zoom_factor);
	return (info);
}

static int	make_pixel(t_vars *vars, t_complex z, t_complex c, t_pixel pixel)
{
	pixel.iterations = vars->info.fractal_func(z, c, vars->info.max_iter);
	if (pixel.iterations > vars->info.max_iter - 1 \
		&& vars->info.settings.d_color == 1)
		return (0);
	pixel.r = (int)(sin(0.036 * (pixel.iterations) + 4) * 130 + 25);
	pixel.g = (int)(sin(0.013 * (pixel.iterations) + 2) * 130 + 25);
	pixel.b = (int)(sin(0.01 * (pixel.iterations) + 1) * 130 + 25);
	return (((int)pixel.r << 16) | ((int)pixel.g << 8) | (int)pixel.b);
}

t_complex	getcomplex(t_pixel pixel, t_info info)
{
	t_complex	c;

	c.real = info.comp.min.real + \
				(info.comp.max.real - info.comp.min.real) * pixel.x / W_W;
	c.imag = info.comp.min.imag + \
				(info.comp.max.imag - info.comp.min.imag) * pixel.y / W_H;
	return (c);
}

void	fast_draw(t_vars *vars)
{
	t_pixel		pixel;
	void		*img_ptr;

	img_ptr = vars->data.addr;
	pixel.y = 0;
	while (pixel.y < W_H)
	{
		pixel.x = 0;
		while (pixel.x < W_W)
		{
			if (!(pixel.x % 2 == 1 || pixel.y % 2 == 1))
				*(uint32_t *)img_ptr = make_pixel(vars, vars->info.z, \
							getcomplex(pixel, calc_coord(vars->info)), pixel);
			else
				*(uint32_t *)img_ptr = 1;
			img_ptr = (uint8_t *)img_ptr + (vars->data.bits_per_pixel / 8);
			pixel.x++;
		}
		pixel.y++;
	}
	odd_pixel((uint32_t *)vars->data.addr);
	even_pixel((uint32_t *)vars->data.addr);
}

typedef struct s_test{
	t_vars			*vars;
	int 			line_counter;
	t_pixel 		*pixel;
	pthread_mutex_t *mutex;
}					t_test;

int cond(t_test *th)
{
	pthread_mutex_lock(th->mutex);
	if(th->line_counter < W_H)
		return (pthread_mutex_unlock(th->mutex), 1);
	return (pthread_mutex_unlock(th->mutex), 0);
}

static int	make_pixel_thread(t_vars *vars, t_com_coord c, pthread_mutex_t *m)
{
	t_vars tmpvars;
	t_pixel pixel;
	(void)m;
	//pthread_mutex_lock(m);
	ft_memcpy(&tmpvars, vars, sizeof(t_vars));
	//tmpvars = *vars;
	//pthread_mutex_unlock(m);

	pixel.iterations = tmpvars.info.fractal_func(c.min, c.max, tmpvars.info.max_iter);
	if (pixel.iterations > tmpvars.info.max_iter - 1 && tmpvars.info.settings.d_color == 1)
		return (0);
	pixel.r = (int)(sin(0.036 * (pixel.iterations) + 4) * 130 + 25);
	pixel.g = (int)(sin(0.013 * (pixel.iterations) + 2) * 130 + 25);
	pixel.b = (int)(sin(0.01 * (pixel.iterations) + 1) * 130 + 25);
	return (((int)pixel.r << 16) | ((int)pixel.g << 8) | (int)pixel.b);
}

void	*line(void *thread)
{
	t_test	*th;
	int		i;
	int 	color;
	void	*line_ptr;

	th = (t_test *)thread;
	printf("thread launched\n");
	pthread_mutex_lock(th->mutex);
	*th->pixel = ((t_pixel){0, 0/*th->line_counter*/, th->vars->info.max_iter, 0, 0, 0});
	pthread_mutex_unlock(th->mutex);
	while (cond(th))
	{
		i = 0;
		line_ptr = th->vars->data.addr + (((th->vars->data.bits_per_pixel / 8) * W_W) * th->line_counter);
		while (i < W_W - 1)
		{
			color = make_pixel_thread(th->vars, (t_com_coord){th->vars->info.z, getcomplex((t_pixel){i, th->line_counter, th->vars->info.max_iter,0,0,0}, calc_coord(th->vars->info))}, th->mutex);
			//color = make_pixel(th->vars, th->vars->info.z, getcomplex((t_pixel){i, th->line_counter, th->vars->info.max_iter,0,0,0}, calc_coord(th->vars->info)), (t_pixel){i,th->line_counter, th->vars->info.max_iter,0,0,0});
			*(uint32_t *)line_ptr = color;
			//*(uint32_t *)line_ptr = 0xff5733;
			line_ptr = (uint8_t *)line_ptr + (th->vars->data.bits_per_pixel / 8);
			th->pixel->x++;
			i++;
		}
		if(th->line_counter < W_H)
			th->line_counter++;
		th->pixel->y++;
		//printf("line: %d\n",th->line_counter);
	}
	return 0;
}

int init_threads(pthread_t *threads, size_t size, t_test *test)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		//pthread_mutex_lock(test->mutex);
		if(pthread_create(threads + i, NULL, &line, (void *)test) != 0)
			return (/*pthread_mutex_unlock(test->mutex),*/ 0);
//		pthread_mutex_unlock(test->mutex);
		i++;
	}
	return (1);
}

void	draw_fractal(t_vars *vars)
{
	pthread_t	threads[4];
	t_pixel 	pixel;
	t_test		test;
	pthread_mutex_t m;
	int				i;

	i = 0;
	test = (t_test){vars, 0, &pixel, &m};
	if(!init_threads(threads, 4, &test))
		return ;
	while (i < 4)
	{
		pthread_join(threads[i], NULL);
		printf("joined\n");
		i++;
	}
}
