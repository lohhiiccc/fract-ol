/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:26 by lrio              #+#    #+#             */
/*   Updated: 2023/12/09 23:00:53 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "mlx.h"
#include "libft.h"
#include "fractol.h"
#include "complex.h"
#include "mouse.h"
#include <stdio.h>

int	close_window(t_vars *vars)
{
    (void)vars;
    exit(0);
}

int keyboard(int key, t_vars *vars)
{
    (void)vars;
    if (key == 65362)
    {
        vars->info.y -= 0.8 / vars->info.zoom_factor;
        //vars->info.comp.max.imag = (vars->info.comp.max.imag - 0.8 / (vars->info.zoom_factor)/*vars->info.y*/);
        //vars->info.comp.min.imag = (vars->info.comp.min.imag - 0.8 / (vars->info.zoom_factor)/*vars->info.y*/);
        draw_fractal(vars, 100);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img,0,0);
        vars->info.y += 0.3 / (2 * vars->info.zoom_factor);
    }
    if(key == 65361)
    {
        vars->info.x -= 0.8 / (vars->info.zoom_factor);
       // vars->info.comp.max.real = (vars->info.comp.max.real - 0.8 / (vars->info.zoom_factor)/*vars->info.y*/);
        //vars->info.comp.min.real = (vars->info.comp.min.real - 0.8 / (vars->info.zoom_factor)/*vars->info.y*/);
        draw_fractal(vars, 100);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img,0,0);
        vars->info.x += 0.3 / (2 * vars->info.zoom_factor);
    }
    if(key == 65363)
    {
        vars->info.x += 0.8 / vars->info.zoom_factor;
        //vars->info.comp.max.real = (vars->info.comp.max.real + 0.8 / (vars->info.zoom_factor)/*vars->info.y*/);
        //vars->info.comp.min.real = (vars->info.comp.min.real + 0.8 / (vars->info.zoom_factor)/*vars->info.y*/);
        draw_fractal(vars, 100);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img,0,0);
        vars->info.x += 0.3 / (vars->info.zoom_factor);
    }
    if (key == 65364)
    {
        vars->info.y += 0.8 / vars->info.zoom_factor;
        //vars->info.comp.max.imag = (vars->info.comp.max.imag + 0.8 / (vars->info.zoom_factor)/*vars->info.y*/);
        //vars->info.comp.min.imag = (vars->info.comp.min.imag + 0.8 / (vars->info.zoom_factor)/*vars->info.y*/);
        draw_fractal(vars, 100);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img,0,0);
        vars->info.y += 0.3 / (vars->info.zoom_factor);
    }
    if(key == 65451) // +
    {
        draw_fractal(vars, 1000);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
    }
    ft_putnbr_fd(key, 1);
    return 0;
}

void loop(t_vars *vars)
{
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
        mlx_hook(vars->win, 17, 0, close_window, &vars);
        mlx_mouse_hook(vars->win, mouse_hook, vars);
        mlx_key_hook(vars->win, keyboard,vars);
        ft_putnbr_fd(vars->info.zoom_factor, 1);
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
    vars.info.x = 0;
    vars.info.y = 0;
    vars.info.fractal_func = &mandelbrot;
    make_image(0,0,1,vars.info.comp, &vars);
    draw_fractal(&vars, 100);
    ft_putnbr_fd(vars.info.zoom_factor, 1);
	ft_putstr_fd("ok", 1);

    loop(&vars);
    return (0);
}
