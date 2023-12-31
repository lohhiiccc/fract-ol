/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:26 by lrio              #+#    #+#             */
/*   Updated: 2023/12/21 21:31:41 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "libft.h"
#include "mouse.h"
#include "keyboard.h"
#define FR_LST "./fractol <julia/mandelbrot/burning_ship>"

int	close_window(t_vars *vars)
{
	return (mlx_loop_end(vars->mlx));
}

int	render_img(t_vars *vars)
{
	if (vars->info.needredraw == 1 || vars->info.needredraw == 2)
	{
		if (vars->info.needredraw == 1)
		{
			fast_draw(vars);
			vars->info.needredraw = 0;
		}
		if (vars->info.needredraw == 2)
		{
			printf("redraw\n");
			draw_fractal(vars);
			vars->info.needredraw = 0;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	}
	return (0);
}

void	loop(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_key_hook(vars->win, keyboard, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	ft_putnbr_fd(vars->info.zoom_factor, 1);
	mlx_loop_hook(vars->mlx, render_img, vars);
	mlx_loop(vars->mlx);
}

static t_fractal_func	get_func(const char *name)
{
	short				i;
	const t_aliasfunc	funcs[3] = {{"julia", 6, &julia}, \
									{"mandelbrot", 11, &mandelbrot}, \
									{"burning_ship", 13, &burning_ship}};

	i = 0;
	while (++i <= 3)
		if (!ft_strncmp(name, funcs[i - 1].fractal_name, funcs[i - 1].len))
			return (funcs[i - 1].fractal_func);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	void	*func;

	if (argc >= 2)
		func = get_func(argv[1]);
	if (argc < 2 || func == NULL)
		return (ft_putstr_fd(FR_LST, 2), -1);
	vars.info.z = (t_complex){0, 0};
	if (argc <= 2 && func == &julia)
		vars.info.z = (t_complex){-0.8, 0.156};
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (ft_putstr_fd("error", 2), -1);
	vars.win = mlx_new_window(vars.mlx, W_W, W_H, "fractal");
	vars.data.img = mlx_new_image(vars.mlx, W_W, W_H);
	vars.data.addr = mlx_get_data_addr(vars.data.img, \
	&vars.data.bits_per_pixel, &vars.data.line_length, &vars.data.endian);
	vars.info = (t_info){func, 0, 0, 0, 1, \
	100, vars.info.z, (t_com_coord){(t_complex){-2.5, -1.5}, \
	(t_complex){2.5, 1.5}}, (t_settings){1, 1}, 1};
	loop(&vars);
	mlx_destroy_image(vars.mlx, vars.data.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}
