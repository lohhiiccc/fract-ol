/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <rio@student.42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:47:53 by lrio              #+#    #+#             */
/*   Updated: 2023/12/08 19:55:55 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

#include <stdio.h>
void draw_fractal(t_vars *vars, int max_iterations)
{
	t_pixel		pixel;
	t_complex	c;

	pixel.x = 0;
	while (pixel.x < W_W)
	{
		pixel.y = 0;
		while (pixel.y < W_H)
		{
			c.real = vars->info.comp.min.real + (vars->info.comp.max.real - vars->info.comp.min.real) * pixel.x / W_W;
			c.imag = vars->info.comp.min.imag + (vars->info.comp.max.imag - vars->info.comp.min.imag) * pixel.y / W_H;
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
