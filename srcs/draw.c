/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:35 by lrio              #+#    #+#             */
/*   Updated: 2023/12/10 15:04:45 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static t_info	calc_coord(t_info initv)
{
	t_info	info;

	info.comp.max.imag = initv.y + (initv.comp.max.imag / initv.zoom_factor);
	info.comp.max.real = initv.x + (initv.comp.max.real / initv.zoom_factor);
	info.comp.min.imag = initv.y + (initv.comp.min.imag / initv.zoom_factor);
	info.comp.min.real = initv.x + (initv.comp.min.real / initv.zoom_factor);
	return (info);
}

static void	make_pixel(t_vars *vars, t_complex c, t_pixel *pixel)
{
	pixel->iterations = vars->info.fractal_func(c, vars->info.max_iter);
	pixel->r = (int)(sin(0.05 * pixel->iterations) * 127);
	pixel->g = (int)(sin(0.03 * pixel->iterations) * 225);
	pixel->b = (int)(sin(0.01 * pixel->iterations) * 127);
	pixel->rgb = (pixel->r << 16) | (pixel->g << 8) | pixel->b;
}

void	draw_fractal(t_vars *vars)
{
	t_pixel		pixel;
	t_complex	c;
	t_info		info;

	pixel.x = 0;
    //void *img_ptr = (int *) vars->img.data->img + 1001;
	info = calc_coord(vars->info);
	while (pixel.x < W_W)
	{
		pixel.y = 0;
		while (pixel.y < W_H)
		{
			c.real = info.comp.min.real + \
					(info.comp.max.real - info.comp.min.real) * pixel.x / W_W;
			c.imag = info.comp.min.imag + \
					(info.comp.max.imag - info.comp.min.imag) * pixel.y / W_H;
			make_pixel(vars, c, &pixel);
			my_mlx_pixel_put(&vars->img, pixel.x, pixel.y, pixel.rgb);
			pixel.y++;
		}
		pixel.x++;
	}
}
