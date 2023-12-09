/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:18 by lrio              #+#    #+#             */
/*   Updated: 2023/12/09 22:22:23 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse.h"
#include "libft.h"
#include "fractol.h"
#include "mlx.h"
#include <stdio.h>

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
    (void)x;
    (void)y;
    if(button == 4)
	{
        vars->info.zoom_factor += 0.2;
        mlx_clear_window(vars->mlx,vars->win);
        make_image(vars->info.x, vars->info.y, vars->info.zoom_factor,
                   zoom(vars->info.comp, &vars->info.zoom_factor, 1, vars->info), vars);
        draw_fractal(vars, 100);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img,0,0);
        return 0;
    }
	if(button == 5)
    {
        vars->info.zoom_factor -= 0.2;
        if (vars->info.zoom_factor < 1)
            return (vars->info.zoom_factor += 0.2, 0);
        mlx_clear_window(vars->mlx, vars->win);
        make_image(vars->info.x, vars->info.y, vars->info.zoom_factor,
                   zoom(vars->info.comp, &vars->info.zoom_factor, 0, vars->info), vars);
        draw_fractal(vars, 100);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
        return 0;
    }
	return 0;
}