/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:35 by lrio              #+#    #+#             */
/*   Updated: 2024/01/02 06:37:05 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"
#include "colorset.h"

static t_info	calc_coord(t_info init_v)
{
	t_info	info;

	info.comp.max.imag = init_v.y + (init_v.comp.max.imag * init_v.zoom_factor);
	info.comp.max.real = init_v.x + (init_v.comp.max.real * init_v.zoom_factor);
	info.comp.min.imag = init_v.y + (init_v.comp.min.imag * init_v.zoom_factor);
	info.comp.min.real = init_v.x + (init_v.comp.min.real * init_v.zoom_factor);
	return (info);
}

static int	make_pixel(t_vars *vars, t_complex z, t_complex c, t_pixel pixel)
{
	int					i;
	const t_colorset	color_tab[] = \
		{&colorset_one, &colorset_two, &colorset_three};

	i = 0;
	pixel.iterations = vars->info.fractal_func(z, c, vars->info.max_iter);
	if (pixel.iterations > vars->info.max_iter - 1 \
		&& vars->info.settings.d_color == 1)
		return (0);
	while (i != vars->info.settings.colorset && i <= 3)
		i++;
	return (color_tab[i - 1](pixel));
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
	vars->info.needredraw = 0;
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
			*(uint32_t *)img_ptr = make_pixel(vars, vars->info.z, \
						getcomplex(pixel, calc_coord(vars->info)), pixel);
			img_ptr = (uint8_t *)img_ptr + (vars->data.bits_per_pixel / 8);
			pixel.x++;
		}
		pixel.y++;
	}
	printf("x: %20.18f\n", vars->info.zoom_factor);
	vars->info.needredraw = 0;
}
