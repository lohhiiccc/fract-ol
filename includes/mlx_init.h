/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:52:59 by lrio              #+#    #+#             */
/*   Updated: 2024/01/02 14:54:36 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H

void	destroy_mlx(t_vars *vars);
int	render_img(t_vars *vars);
void	loop(t_vars *vars);
int	initvar(t_vars *vars);
int	close_window(t_vars *vars);

#endif
