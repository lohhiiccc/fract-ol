/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:18 by lrio              #+#    #+#             */
/*   Updated: 2023/12/12 16:03:58 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"
#include "mlx.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
    (void)x;
    (void)y;
    if(button == MOUSE_S_UP)
	{
        vars->info.zoom_factor *= 1.5;
		fast_draw(vars);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
    }
	if(button == MOUSE_S_DOWN)
    {
        vars->info.zoom_factor *= 0.5;
		fast_draw(vars);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
    }
	return 0;
}