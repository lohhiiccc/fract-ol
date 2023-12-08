/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:39:03 by lrio              #+#    #+#             */
/*   Updated: 2023/12/08 19:56:10 by lrio             ###   ########.fr       */
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

t_com_coord edit_coord(t_com_coord c, double x, double y, double zoom)
{
	t_com_coord r;

	r.max.real = (c.max.real + x) / zoom;
	r.max.imag = (c.max.imag + y) / zoom;
	r.min.real = (c.min.real + x) / zoom;
	r.min.imag = (c.min.imag + y) / zoom;
	return (r);
}

void make_image(double x, double y, double zoom, t_com_coord comp,t_vars *vars)
{
    vars->info.x = x;
    vars->info.y = y;
    vars->info.zoom_factor = zoom;
    vars->info.comp = comp;
}

void loop(t_vars *vars)
{
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
    mlx_hook(vars->win, 17, 0, close_window, &vars);
    mlx_mouse_hook(vars->win, mouse_hook, &vars);
    mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	if(argc == 0) return 0;
	(void)argv;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, W_W, W_H, "fractal");
	vars.img.img = mlx_new_image(vars.mlx, W_W, W_H);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, \
	&vars.img.line_length, &vars.img.endian);
    vars.info.comp = (t_com_coord){(t_complex){-2.5, -1.5}, (t_complex){2.5, 1.5}};
    vars.info.fractal_func = &mandelbrot;

    make_image(0,0,1,vars.info.comp, &vars);
    draw_fractal(&vars, 100);
	ft_putstr_fd("ok", 1);

    loop(&vars);
return (0);
}
