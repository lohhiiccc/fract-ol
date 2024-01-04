/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:26:03 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 15:20:08 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H
# ifndef NB_THREADS
	# define NB_THREADS 4
# endif
# include <pthread.h>
# include "fractol.h"

void		flush_buffer(uint32_t line, t_engine *vars, uint32_t *buffer_line);
//t_pixel		fill_buffer(t_pixel *pixel, t_engine *vars, uint32_t *buffer_line, uint32_t i);
int			inti_thread(void *(*start_routine) (void *), void *args);
#endif