/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:18 by lrio              #+#    #+#             */
/*   Updated: 2023/12/15 22:49:42 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "keyboard.h"
#include "mlx.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == MOUSE_S_UP || button == MOUSE_S_DOWN)
	{
		t_complex cc;
		cc = (t_complex){(double) x / W_W , (double)y / W_H};

		printf("\n x: %f", vars->info.x);
		//vars->info.x += (double)cc.real / W_W;
//		vars->info.y = (double)y / W_H;
		if (button == MOUSE_S_UP)
			vars->info.zoom_factor *= 1.5;
		else if (button == MOUSE_S_DOWN)
			vars->info.zoom_factor *= 0.5;
		vars->info.needredraw = 1;


	}
	return (0);
}
