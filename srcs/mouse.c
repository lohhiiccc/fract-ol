/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:18 by lrio              #+#    #+#             */
/*   Updated: 2023/12/31 19:31:24 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "keyboard.h"

static void	scroll_up(t_vars *vars, int x, int y)
{
	y = (y - W_H / 2);
	x = (x - W_W / 2);
	vars->info.zoom_factor *=0.5;
	vars->info.needredraw = 1;
}

static void	scroll_down(t_vars *vars)
{
	vars->info.zoom_factor *=1.5;
	vars->info.needredraw = 1;
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == MOUSE_S_UP || button == MOUSE_S_DOWN)
	{
		if (button == MOUSE_S_UP)
			scroll_up(vars, x, y);
		else if (button == MOUSE_S_DOWN)
			scroll_down(vars);
		printf("debug: %f | %f\n", vars->info.x, vars->info.y);
	}
	return (0);
}
