/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:35 by lrio              #+#    #+#             */
/*   Updated: 2023/12/16 07:22:15 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include "pixel.h"

static t_info	calc_coord(t_info initv)
{
	t_info	info;

	info.comp.max.imag = initv.y + (initv.comp.max.imag / initv.zoom_factor);
	info.comp.max.real = initv.x + (initv.comp.max.real / initv.zoom_factor);
	info.comp.min.imag = initv.y + (initv.comp.min.imag / initv.zoom_factor);
	info.comp.min.real = initv.x + (initv.comp.min.real / initv.zoom_factor);
	return (info);
}

static int	make_pixel(t_vars *vars, t_complex z, t_complex c, t_pixel pixel)
{
	pixel.iterations = vars->info.fractal_func(z, c, vars->info.max_iter);
	if (pixel.iterations > vars->info.max_iter - 1 \
		&& vars->info.settings.d_color == 1)
		return (0);
	pixel.r = (int)(sin(0.036 * (pixel.iterations) + 4) * 130 + 25);
	pixel.g = (int)(sin(0.013 * (pixel.iterations) + 2) * 130 + 25);
	pixel.b = (int)(sin(0.01 * (pixel.iterations) + 1) * 130 + 25);
	return (((int)pixel.r << 16) | ((int)pixel.g << 8) | (int)pixel.b);
}

t_complex	getcomplex(t_pixel pixel, t_info info)
{
	t_complex	c;

	c.real = info.comp.min.real + \
				(info.comp.max.real - info.comp.min.real) * pixel.x / W_W;
	c.imag = info.comp.min.imag + \
				(info.comp.max.imag - info.comp.min.imag) * pixel.y / W_H;
	return (c);
}

void	fast_draw(t_vars *vars)
{
	t_pixel		pixel;
	void		*img_ptr;

	img_ptr = vars->data.addr;
	pixel.y = 0;
	while (pixel.y < W_H)
	{
		pixel.x = 0;
		while (pixel.x < W_W)
		{
			if (!(pixel.x % 2 == 1 || pixel.y % 2 == 1))
				*(uint32_t *)img_ptr = make_pixel(vars, vars->info.z, \
							getcomplex(pixel, calc_coord(vars->info)), pixel);
			else
				*(uint32_t *)img_ptr = 1;
			img_ptr = (uint8_t *)img_ptr + (vars->data.bits_per_pixel / 8);
			pixel.x++;
		}
		pixel.y++;
	}
	odd_pixel((uint32_t *)vars->data.addr);
	even_pixel((uint32_t *)vars->data.addr);
}

void	draw_fractal(t_vars *vars)
{
	t_pixel		pixel;
	void		*img_ptr;

	pixel.y = 0;
	img_ptr = vars->data.addr;
	while (pixel.y < W_H)
	{
		pixel.x = 0;
		while (pixel.x < W_W)
		{
			*(uint32_t *)img_ptr = make_pixel(vars, (t_complex){0, 0}, \
						getcomplex(pixel, calc_coord(vars->info)), pixel);
			img_ptr = (uint8_t *)img_ptr + (vars->data.bits_per_pixel / 8);
			pixel.x++;
		}
		pixel.y++;
	}
}
