/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:35 by lrio              #+#    #+#             */
/*   Updated: 2023/12/12 01:17:18 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

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

typedef struct s_rgb{
	uint32_t 	r;
	uint32_t 	g;
	uint32_t 	b;
	uint32_t 	*addr;
}	t_rgb;

typedef struct s_corner_around_p{
	t_rgb lup;
	t_rgb rup;
	t_rgb dlp;
	t_rgb drp;
}	t_corner_around_p;

static t_rgb uncolor(uint32_t color)
{
	t_rgb c;
	c.r = (color >> 16) & 0xFF;
	c.g = (color >> 8) & 0xFF;
	c.b = (color & 0xFF);

	return c;
}


static t_corner_around_p uncolorall(t_corner_around_p area)
{
	area.lup = uncolor(*area.lup.addr);
	area.rup = uncolor(*area.rup.addr);
	area.dlp = uncolor(*area.dlp.addr);
	area.drp = uncolor(*area.drp.addr);
	return (area);
}

static t_rgb average_rgb(t_corner_around_p around) {
	t_rgb avg;
	avg.r = (around.lup.r + around.rup.r + around.dlp.r + around.drp.r) >> 2;
	avg.g = (around.lup.g + around.rup.g + around.dlp.g + around.drp.g) >> 2;
	avg.b = (around.lup.b + around.rup.b + around.dlp.b + around.drp.b) >> 2;
	return avg;
}

static uint32_t get_color(t_corner_around_p around)
{
	t_rgb avg = average_rgb(around);
	return ((avg.r << 16) | (avg.g << 8) | avg.b);
}

typedef struct s_coord{
	size_t x;
	size_t y;
}	t_coord;

void fill_image(t_vars *vars)
{
	uint32_t *img_ptr = (uint32_t *)vars->img.addr;
	t_corner_around_p c;
	uint32_t *center_pixel;
	t_coord coord;

	coord.y = 0;
	while (coord.y < W_H)
	{
		coord.x = 0;
		while (coord.x < W_W)
		{
			if (coord.x % 2 == 1 && coord.y % 2 == 1)
			{
				center_pixel = img_ptr + coord.y * W_W + coord.x;
				c.lup.addr = img_ptr + (coord.y - 1) * W_W + coord.x - 1;
				c.rup.addr = img_ptr + (coord.y - 1) * W_W + coord.x + 1;
				c.dlp.addr = img_ptr + (coord.y + 1) * W_W + coord.x - 1;
				c.drp.addr = img_ptr + (coord.y + 1) * W_W + coord.x + 1;

				*center_pixel = (get_color(uncolorall(c)));
			}
			coord.x += 1;
		}
		coord.y += 1;
	}
}

void	fast_draw(t_vars *vars)
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
		//		*(uint32_t *) img_ptr = -1;
				img_ptr = (uint8_t *) img_ptr + (vars->img.bits_per_pixel / 8);
			}
			pixel.x++;
		}
		pixel.y++;
	}
	fill_image(vars);
	end = clock();
	elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
	printf("Time to render a frame %.2f ms.\n", elapsed_time);
}

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