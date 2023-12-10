/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:35 by lrio              #+#    #+#             */
/*   Updated: 2023/12/10 01:32:44 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void make_image(double x, double y, double zoom, t_com_coord comp,t_vars *vars)
{
    vars->info.x = x;
    vars->info.y = y;
    vars->info.zoom_factor = zoom;
    vars->info.comp = comp;
}

void draw_fractal(t_vars *vars, int max_iterations)
{
	t_pixel		pixel;
	t_complex	c;
    t_info info;
    pixel.x = 0;
    //void *img_ptr = (int *) vars->img.data->img + 1001;

    info.comp.max.imag = vars->info.y + (vars->info.comp.max.imag / vars->info.zoom_factor);
    info.comp.max.real = vars->info.x + (vars->info.comp.max.real / vars->info.zoom_factor);
    info.comp.min.imag = vars->info.y + (vars->info.comp.min.imag / vars->info.zoom_factor);
	info.comp.min.real = vars->info.x + (vars->info.comp.min.real / vars->info.zoom_factor);
    while (pixel.x < W_W)
	{
		pixel.y = 0;
		while (pixel.y < W_H)
		{
            c.real = info.comp.min.real + (info.comp.max.real - info.comp.min.real) * pixel.x / W_W;
			c.imag = info.comp.min.imag + (info.comp.max.imag - info.comp.min.imag) * pixel.y / W_H;
			pixel.iterations = vars->info.fractal_func(c, max_iterations);
			pixel.r = (int)(sin(0.05 * pixel.iterations) * 127);
			pixel.g = (int)(sin(0.03 * pixel.iterations) * 225);
			pixel.b = (int)(sin(0.01 * pixel.iterations) * 127);
			pixel.rgb = (pixel.r << 16) | (pixel.g << 8) | pixel.b;
			my_mlx_pixel_put(&vars->img, pixel.x, pixel.y, pixel.rgb);
			pixel.y++;
		}
		pixel.x++;
	}
}
