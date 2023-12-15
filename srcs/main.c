/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:26 by lrio              #+#    #+#             */
/*   Updated: 2023/12/15 15:30:36 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "mouse.h"
#include "keyboard.h"

int	close_window(t_vars *vars)
{
	return (mlx_loop_end(vars->mlx));
}

int re(t_vars *vars)
{
	if(vars->info.needredraw == 1)
	{
		fast_draw(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,vars->data.img, 0, 0);
	}
	if (vars->info.needredraw == 2)
	{
		draw_fractal(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,vars->data.img, 0, 0);
	}
	return 0;
}

void	loop(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_key_hook(vars->win, keyboard, vars);
	mlx_hook(vars->win, 17, 0, close_window, &vars);
	ft_putnbr_fd(vars->info.zoom_factor, 1);
	mlx_loop_hook(vars->mlx, re, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void)argc;
	(void)argv;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, W_W, W_H, "fractal");
	vars.data.img = mlx_new_image(vars.mlx, W_W, W_H);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel, &vars.data.line_length, &vars.data.endian);
	vars.info = (t_info){&julia, 0, 0, 0, 1, 100, (t_com_coord){(t_complex){-2.5, -1.5}, (t_complex){2.5, 1.5}},(t_settings){1, 1}, 1};

    loop(&vars);
	mlx_destroy_display(vars.mlx);
	mlx_destroy_image(vars.mlx,vars.data.img);
	mlx_destroy_window(vars.mlx, vars.win);
	return (0);
}
