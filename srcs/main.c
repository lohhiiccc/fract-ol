/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:26 by lrio              #+#    #+#             */
/*   Updated: 2023/12/11 21:03:29 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fractol.h"
#include "complex.h"
#include "mouse.h"
#include "keyboard.h"

int	close_window(t_vars *vars)
{
	(void)vars;
	exit(0);
}

void	loop(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_hook(vars->win, 17, 0, close_window, &vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_key_hook(vars->win, keyboard, vars);
	ft_putnbr_fd(vars->info.zoom_factor, 1);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void)argc;
	(void)argv;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, W_W, W_H, "fractal");
	vars.img.img = mlx_new_image(vars.mlx, W_W, W_H);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, \
	&vars.img.line_length, &vars.img.endian);
    vars.info.comp = (t_com_coord){(t_complex){-2.5, -1.5}, (t_complex){2.5, 1.5}};
    vars.info.x = 0;
    vars.info.y = 0;
    vars.info.max_iter = 100;
	vars.info.zoom_factor = 0.5;
    vars.info.fractal_func = &burning_ship;

	fast_draw(&vars);
    ft_putnbr_fd(vars.info.zoom_factor, 1);
	ft_putstr_fd("ok", 1);

    loop(&vars);
    return (0);
}
