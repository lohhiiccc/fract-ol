/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:39:03 by lrio              #+#    #+#             */
/*   Updated: 2023/12/07 17:51:13 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "mlx.h"
#include "libft.h"
#include "fractol.h"
#include "complex.h"
#include "mouse.h"






int	close_window(void)
{
	exit(0);
}

t_com_coord edit_fractal(t_com_coord c, double x, double y, double zoom)
{
	t_com_coord r;

	(void)zoom;
	r.max.real = c.max.real + x;
	r.max.imag = c.max.imag + y;
	r.min.real = c.min.real + x;
	r.min.imag = c.min.imag + y;
	return (r);
}
int	main(int argc, char **argv)
{
	if(argc == 0) return 0;
	(void)argv;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, W_W, W_H, "Mandelbrot");
	vars.img.img = mlx_new_image(vars.mlx, W_W, W_H);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, \
	&vars.img.line_length, &vars.img.endian);

	vars.info.fractal_func = &mandelbrot;
	vars.info.x = 0;
	vars.info.y = 0;
	draw_fractal(&vars.img, edit_fractal((t_com_coord){(t_complex){-3.5, -1.5}, (t_complex){2.5, 0.5}},0,0,1), 1000, &mandelbrot);

	ft_putstr_fd("ok", 1);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
