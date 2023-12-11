/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:35 by lrio              #+#    #+#             */
/*   Updated: 2023/12/11 21:32:23 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef struct unit32_t unit32_t;

static t_info	calc_coord(t_info initv)
{
	t_info	info;

	info.comp.max.imag = initv.y + (initv.comp.max.imag / initv.zoom_factor);
	info.comp.max.real = initv.x + (initv.comp.max.real / initv.zoom_factor);
	info.comp.min.imag = initv.y + (initv.comp.min.imag / initv.zoom_factor);
	info.comp.min.real = initv.x + (initv.comp.min.real / initv.zoom_factor);
	return (info);
}

static int make_pixel(t_vars *vars, t_complex c, t_pixel pixel)
{
	pixel.iterations = vars->info.fractal_func(c, vars->info.max_iter);
	pixel.r = (int)(sin(0.05 * pixel.iterations) * 127);
	pixel.g = (int)(sin(0.03 * pixel.iterations) * 225);
	pixel.b = (int)(sin(0.01 * pixel.iterations) * 127);
	return ((pixel.r << 16) | (pixel.g << 8) | pixel.b);
}

void	fill_image(t_vars *vars)
{
	t_pixel	pixel;
	void *img_ptr = vars->img.addr;
	pixel.y = 0;
	while (pixel.y < W_H)
	{
		pixel.x = 0;
		while (pixel.x < W_W)
		{
			if (pixel.x % 2 == 1)
			{
				if(pixel.x != 0 && pixel.y != 0 && pixel.x < W_W - 1 && pixel.y < W_H)
				{
					*(uint32_t *) img_ptr = 225;
					img_ptr = (uint8_t *) img_ptr + (vars->img.bits_per_pixel / 8);
				}
				img_ptr = (uint8_t *) img_ptr + (vars->img.bits_per_pixel / 8);
			}

			pixel.x++;
		}
		pixel.y++;
	}
}

void	fast_draw(t_vars *vars)
{
	t_pixel		pixel;
	t_complex	c;
	t_info		info;

	pixel.y = 0;
	void *img_ptr = vars->img.addr;
	info = calc_coord(vars->info);
	while (pixel.y < W_H)
	{
		pixel.x = 0;
		while (pixel.x < W_W)
		{
			if(!(pixel.x % 2 == 1 || pixel.y % 2 == 1))
			{
				c.real = info.comp.min.real + \
                    (info.comp.max.real - info.comp.min.real) * pixel.x / W_W;
				c.imag = info.comp.min.imag + \
                    (info.comp.max.imag - info.comp.min.imag) * pixel.y / W_H;
				*(uint32_t *) img_ptr = make_pixel(vars, c, pixel);
				img_ptr = (uint8_t *) img_ptr + (vars->img.bits_per_pixel / 8);
			}
			else
			{
				*(uint32_t *) img_ptr = 0;
				img_ptr = (uint8_t *) img_ptr + (vars->img.bits_per_pixel / 8);
			}
			pixel.x++;
		}
		pixel.y++;
	}
	fill_image(vars);
	/*
	pixel = (t_pixel){0,0,0,0,0,0};
	while (pixel.y < W_H)
	{
		pixel.x = 0;
		while (pixel.x < W_W)
		{

		}
	}
	while ()
	end = clock();
	elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
	printf("Time to render a frame %.2f ms.\n", elapsed_time);
*/}

void	draw_fractal(t_vars *vars)
{
	t_pixel		pixel;
	t_complex	c;
	t_info		info;
	clock_t start, end;
	double elapsed_time;

	start = clock();
	pixel.y = 0;
	void *img_ptr = vars->img.addr;
	info = calc_coord(vars->info);
	while (pixel.y < W_H)
	{
		pixel.x = 0;
		while (pixel.x < W_W)
		{
			c.real = info.comp.min.real + \
					(info.comp.max.real - info.comp.min.real) * pixel.x / W_W;
			c.imag = info.comp.min.imag + \
					(info.comp.max.imag - info.comp.min.imag) * pixel.y / W_H;
			*(uint32_t *)img_ptr = make_pixel(vars, c, pixel);
			img_ptr = (uint8_t *) img_ptr + (vars->img.bits_per_pixel / 8);
			pixel.x++;
		}
		pixel.y++;
	}
	end = clock();
	elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
	printf("Time to render a frame %.2f ms.\n", elapsed_time);
}