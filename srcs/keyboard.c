/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:29:33 by lrio              #+#    #+#             */
/*   Updated: 2023/12/12 16:27:46 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"
#include "keyboard.h"
#include "mlx.h"

int	keyboard(int key, t_vars *vars)
{
	if (key == A_UP)
		arrow_up(vars);
	if (key == A_LEFT)
		arrow_left(vars);
	if (key == A_RIGHT)
		arrow_right(vars);
	if (key == A_DOWN)
		arrow_down(vars);
	if (key == KEY_MINUS)
	{
		vars->info.max_iter *= 2;
		fast_draw(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	}
	if (key == KEY_PLUS)
	{
		vars->info.max_iter /= 2;
		if (vars->info.max_iter < 50)
			vars->info.max_iter = 50;
		fast_draw(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	}
	if (key == 65307)
		exit(0);
	if (key == 32)
	{
		if (vars->info.methode_type == 0)
			vars->info.methode_type = 1;
		else
			vars->info.methode_type = 0;
		draw_fractal(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	}
	else
		printf("touche: %d\n", key);
	return (0);
}
