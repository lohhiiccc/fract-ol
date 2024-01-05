/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:34:49 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 11:34:54 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H

void	destroy_mlx(t_engine *vars);
int		render_img(t_engine *vars);
void	loop(t_engine *vars);
int		initvar(t_engine *vars);
int		close_window(t_engine *vars);

#endif