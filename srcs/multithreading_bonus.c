/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:50:47 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 15:37:52 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"
#include "fractol.h"

int	close_previous_threads(int i, pthread_t *threads)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_cancel(threads[i]);
		j++;
	}
	return (-1);
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
		if (-1 == pthread_create(threads + i, NULL, start_routine, args))
			return (close_previous_threads(i, threads));
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

void	flush_buffer(uint32_t line, t_engine *vars, uint32_t *buffer_line)
{
	void	*img_ptr;
	t_pixel pixel;

	(void)buffer_line;
	pixel.x = 0;
	pixel.y = line;
	img_ptr = vars->img.addr + W_W * line * (vars->img.bits_per_pixel >> 3);
	while (pixel.x < W_W)
	{
//		*(uint32_t *)img_ptr = buffer_line[x];
		*(uint32_t *)img_ptr = make_pixel(vars, vars->fractal.z, \
					getcomplex(pixel, calc_coord(vars->fractal)), pixel);
//		*(uint32_t *)img_ptr = 255;
//		if (pixel.x != W_W)
		img_ptr = (uint8_t *)img_ptr + (vars->img.bits_per_pixel >> 3);
		pixel.x++;
	}
}
/*
t_pixel	fill_buffer \
(t_pixel *pixel, t_engine *vars, uint32_t *buffer_line, uint32_t i)
{
	while ((*pixel).x < W_W)
	{
		i++;
		(*pixel).x++;
	}
	return (*pixel);
}
*/