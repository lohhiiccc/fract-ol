/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:22:42 by lrio              #+#    #+#             */
/*   Updated: 2024/01/01 01:28:28 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"
#include "fractol.h"
#include "mlx.h"

void	arrow_up(t_vars *vars)
{
	if (vars->info.y - 0.8 * (1.6 * vars->info.zoom_factor) < -2)
		vars->info.y = -2;
	else
		vars->info.y -= 0.8 * (1.6 * vars->info.zoom_factor);
	vars->info.needredraw = 1;
}

void	arrow_down(t_vars *vars)
{
	if (vars->info.y + 0.8 * (1.6 * vars->info.zoom_factor) > 2)
		vars->info.y = 2;
	else
		vars->info.y += 0.8 * (1.6 * vars->info.zoom_factor);
	vars->info.needredraw = 1;
}

void	arrow_left(t_vars *vars)
{
	if (vars->info.x - 0.8 * (1.6 * vars->info.zoom_factor) < -2)
		vars->info.x = -2;
	else
		vars->info.x -= 0.8 * (1.6 * vars->info.zoom_factor);
	vars->info.needredraw = 1;
}

void	arrow_right(t_vars *vars)
{
	if (vars->info.x + 0.8 * (1.6 * vars->info.zoom_factor) > 2)
		vars->info.x = 2;
	else
		vars->info.x += 0.8 * (1.6 * vars->info.zoom_factor);
	vars->info.needredraw = 1;
}
