/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:50:47 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 15:07:59 by lrio             ###   ########.fr       */
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

void	flush_buffer(t_pixel *pixel, t_engine *vars, uint32_t *buffer_line)
{
	void	*img_ptr;
	int		y;

	y = 0;
	pthread_mutex_lock(&vars->mutex_img);
	img_ptr = vars->img.addr + W_W * (*pixel).y * \
		(vars->img.bits_per_pixel >> 3);
	while (y < W_W - 1)
	{
		*(uint32_t *)img_ptr = buffer_line[y];
		img_ptr = (uint8_t *)img_ptr + (vars->img.bits_per_pixel >> 3);
		y++;
	}
	pthread_mutex_unlock(&vars->mutex_img);
}

t_pixel	fill_buffer \
(t_pixel *pixel, t_engine *vars, uint32_t *buffer_line, uint32_t i)
{
	while ((*pixel).x < W_W)
	{
		buffer_line[i] = make_pixel(vars, vars->fractal.z, \
					getcomplex((*pixel), calc_coord(vars->fractal)), (*pixel));
		i++;
		(*pixel).x++;
	}
	return (*pixel);
}
