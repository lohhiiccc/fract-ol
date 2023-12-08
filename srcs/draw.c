/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <rio@student.42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:47:53 by lrio              #+#    #+#             */
/*   Updated: 2023/12/08 14:05:06 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	draw_fractal(t_data *img, t_com_coord comp, int max_iterations,int (*f)(t_complex, int))
{
	t_pixel		pixel;
	t_complex	c;

	pixel.x = 0;
	while (pixel.x < W_W)
	{
		pixel.y = 0;
		while (pixel.y < W_H)
		{
			c.real = comp.min.real + (comp.max.real - comp.min.real) * pixel.x / W_W;
			c.imag = comp.min.imag + (comp.max.imag - comp.min.imag) * pixel.y / W_H;
			pixel.iterations = f(c, max_iterations);
			pixel.r = (int)(sin(0.05 * pixel.iterations) * 127);
			pixel.g = (int)(sin(0.03 * pixel.iterations) * 225);
			pixel.b = (int)(sin(0.01 * pixel.iterations) * 127);
			pixel.rgb = (pixel.r << 16) | (pixel.g << 8) | pixel.b;
			my_mlx_pixel_put(img, pixel.x, pixel.y, pixel.rgb);
			pixel.y++;
		}
		pixel.x++;
	}
}
