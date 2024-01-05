/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:50:38 by lrio              #+#    #+#             */
/*   Updated: 2024/01/05 16:07:04 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"
#include "mlx_init.h"
#include "mouse.h"
#include "keyboard.h"

int	close_window(t_vars *vars)
{
	return (mlx_loop_end(vars->mlx));
}

int	initvar(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (ft_putstr_fd("error", 2), -1);
	vars->win = mlx_new_window(vars->mlx, W_W, W_H, "fractol");
	vars->data.img = mlx_new_image(vars->mlx, W_W, W_H);
	vars->data.addr = mlx_get_data_addr(vars->data.img, \
	&vars->data.bits_per_pixel, &vars->data.line_length, &vars->data.endian);
	return (0);
}

void	destroy_mlx(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

void	loop(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_key_hook(vars->win, keyboard, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_loop_hook(vars->mlx, render_img, vars);
	mlx_loop(vars->mlx);
}

int	close_fd_and_mlx(int fd, t_vars *vars)
{
	close(fd);
	return (close_window(vars));
}
