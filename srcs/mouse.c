/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:18 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 09:35:52 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "keyboard.h"

double	capnum(int cap, double num)
{
	if (num > (float)cap || num < -(float)cap)
	{
		if (num > (float)cap)
			return (-cap);
		return (cap);
	}
	return (num);
}

static void	scroll_up(t_engine *vars, int x, int y)
{
	vars->fractal.zoom_factor *= 0.5;
	vars->fractal.x = capnum(2, (vars->fractal.x + \
		(((x - W_W * 0.5) / (0.2000 * W_W)) * vars->fractal.zoom_factor)));
	vars->fractal.y = capnum(2, (vars->fractal.y + \
		(((y - W_H * 0.5) / (0.3375 * W_H)) * vars->fractal.zoom_factor)));
	vars->fractal.zoom_factor *= 1.5;
	vars->fractal.needredraw = 1;
}

static void	scroll_down(t_engine *vars)
{
	vars->fractal.zoom_factor *= 1.5;
	vars->fractal.needredraw = 1;
}

static void	left_click(t_engine *vars, int x, int y)
{
	vars->fractal.x = capnum(2, ((vars->fractal.x + \
		(((x - W_W * 0.5) / (0.2000 * W_W))) * vars->fractal.zoom_factor)));
	vars->fractal.y = capnum(2, ((vars->fractal.y + \
		(((y - W_H * 0.5) / (0.3375 * W_H))) * vars->fractal.zoom_factor)));
	vars->fractal.needredraw = 1;
}

int	mouse_hook(int button, int x, int y, t_engine *vars)
{
	if (button == MOUSE_S_UP || button == MOUSE_S_DOWN || button == LEFT_CLICK)
	{
		if (button == MOUSE_S_UP)
			scroll_up(vars, x, y);
		else if (button == MOUSE_S_DOWN)
			scroll_down(vars);
		else
			left_click(vars, x, y);
	}
	return (0);
}
