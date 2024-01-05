/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:34:49 by lrio              #+#    #+#             */
/*   Updated: 2024/01/05 12:25:45 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H

int		close_fd_and_mlx(int fd, t_engine *vars);
void	destroy_mlx(t_engine *vars);
int		render_img(t_engine *vars);
void	loop(t_engine *vars);
int		initvar(t_engine *vars);
int		close_window(t_engine *vars);

#endif