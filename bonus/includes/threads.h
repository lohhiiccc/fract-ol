/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:26:03 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 17:08:35 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H
# ifndef NB_THREADS
#  define NB_THREADS 1
# endif
# include "fractol.h"

void		draw_half_line(uint32_t line, t_engine *vars);
void		draw_line(uint32_t line, t_engine *vars);
int			inti_thread(void *(*start_routine) (void *), void *args);
#endif