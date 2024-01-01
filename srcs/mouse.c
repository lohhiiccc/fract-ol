/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:18 by lrio              #+#    #+#             */
/*   Updated: 2024/01/01 03:29:49 by lrio             ###   ########.fr       */
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

static void	scroll_up(t_vars *vars, int x, int y)
{
	vars->info.zoom_factor *= 0.5;
	vars->info.x = capnum(2, (vars->info.x + \
		(((x - W_W / 2.0) / (0.2000 * W_W)) * vars->info.zoom_factor)));
	vars->info.y = capnum(2, (vars->info.y + \
		(((y - W_H / 2.0) / (0.3375 * W_H)) * vars->info.zoom_factor)));
	vars->info.zoom_factor *= 1.5;
	vars->info.needredraw = 1;
}

static void	scroll_down(t_vars *vars)
{
	vars->info.zoom_factor *= 1.5;
	vars->info.needredraw = 1;
}

static void	left_click(t_vars *vars, int x, int y)
{
	vars->info.x = capnum(2, (vars->info.x + \
		(((x - W_W / 2.0) / (0.2000 * W_W)) * vars->info.zoom_factor)));
	vars->info.y = capnum(2, (vars->info.y + \
		(((y - W_H / 2.0) / (0.3375 * W_H)) * vars->info.zoom_factor)));
	vars->info.needredraw = 1;
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == MOUSE_S_UP || button == MOUSE_S_DOWN || button == 1)
	{
		if (button == MOUSE_S_UP)
			scroll_up(vars, x, y);
		else if (button == MOUSE_S_DOWN)
			scroll_down(vars);
		else
			left_click(vars, x, y);
	}
	printf("key: %d\n", button);
	return (0);
}
