/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:22:42 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 17:13:32 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"

void	arrow_up(t_engine *vars)
{
	if (vars->fractal.y - 0.8 * (1.6 * vars->fractal.zoom_factor) < -2)
		vars->fractal.y = -2;
	else
		vars->fractal.y -= 0.8 * (1.6 * vars->fractal.zoom_factor);
	vars->fractal.needredraw = 1;
}

void	arrow_down(t_engine *vars)
{
	if (vars->fractal.y + 0.8 * (1.6 * vars->fractal.zoom_factor) > 2)
		vars->fractal.y = 2;
	else
		vars->fractal.y += 0.8 * (1.6 * vars->fractal.zoom_factor);
	vars->fractal.needredraw = 1;
}

void	arrow_left(t_engine *vars)
{
	if (vars->fractal.x - 0.8 * (1.6 * vars->fractal.zoom_factor) < -2)
		vars->fractal.x = -2;
	else
		vars->fractal.x -= 0.8 * (1.6 * vars->fractal.zoom_factor);
	vars->fractal.needredraw = 1;
}

void	arrow_right(t_engine *vars)
{
	if (vars->fractal.x + 0.8 * (1.6 * vars->fractal.zoom_factor) > 2)
		vars->fractal.x = 2;
	else
		vars->fractal.x += 0.8 * (1.6 * vars->fractal.zoom_factor);
	vars->fractal.needredraw = 1;
}
