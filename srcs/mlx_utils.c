/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:50:38 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 17:16:13 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "mouse.h"
#include "keyboard.h"
#include "mlx_init.h"

int	close_window(t_engine *vars)
{
	return (mlx_loop_end(vars->mlx));
}

int	initvar(t_engine *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (ft_putstr_fd("error", 2), -1);
	vars->win = mlx_new_window(vars->mlx, W_W, W_H, "fractol");
	vars->img.img = mlx_new_image(vars->mlx, W_W, W_H);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
	&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	return (0);
}

void	destroy_mlx(t_engine *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

void	loop(t_engine *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_key_hook(vars->win, keyboard, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_loop_hook(vars->mlx, render_img, vars);
	mlx_loop(vars->mlx);
}
