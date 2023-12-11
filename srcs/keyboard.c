/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:29:33 by lrio              #+#    #+#             */
/*   Updated: 2023/12/10 15:13:45 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		draw_fractal(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	if (key == KEY_PLUS)
	{
		vars->info.max_iter /= 2;
		if (vars->info.max_iter < 50)
			vars->info.max_iter = 50;
		draw_fractal(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	return (0);
}