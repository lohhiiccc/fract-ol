/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:18 by lrio              #+#    #+#             */
/*   Updated: 2023/12/31 20:39:23 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "keyboard.h"

static void	scroll_up(t_vars *vars, int x, int y)
{
	double debuga =(x - W_W / 2);
	double debugb =(y - W_H / 2);
	printf("---------------------------------------\nx: %d\t\t|\ty: %d\nx: %f\t|\ty: %f\nx: %f\t|\ty: %f\n", x, y, debuga, debugb, vars->info.x, vars->info.y);
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
	}
	return (0);
}
