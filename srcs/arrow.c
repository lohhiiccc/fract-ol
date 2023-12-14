/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:22:42 by lrio              #+#    #+#             */
/*   Updated: 2023/12/12 16:27:05 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"
#include "fractol.h"
#include "mlx.h"

void	arrow_up(t_vars *vars)
{
	vars->info.y -= 0.8 / vars->info.zoom_factor;
	fast_draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	vars->info.y += 0.3 / (2 * vars->info.zoom_factor);
}

void	arrow_down(t_vars *vars)
{
	vars->info.y += 0.8 / vars->info.zoom_factor;
	fast_draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	vars->info.y += 0.3 / (vars->info.zoom_factor);
}

void	arrow_left(t_vars *vars)
{
	vars->info.x -= 0.8 / (vars->info.zoom_factor);
	fast_draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	vars->info.x += 0.3 / (2 * vars->info.zoom_factor);
}

void	arrow_right(t_vars *vars)
{
	vars->info.x += 0.8 / vars->info.zoom_factor;
	fast_draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	vars->info.x += 0.3 / (vars->info.zoom_factor);
}
