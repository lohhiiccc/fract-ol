/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:39:03 by lrio              #+#    #+#             */
/*   Updated: 2023/12/05 22:32:46 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fractol.h"
#include "complex.h"
#include <math.h>

#define W_W 1000
#define W_H 900

#define INITIAL_WIDTH 800
#define INITIAL_HEIGHT 600


int	mandelbrot(t_complex c, int max_iterations)
{
	t_complex	num;
	int			iter;

	iter = 0;
	num.real = 0;
	num.imag = 0;
	while (iter < max_iterations && magnitude_squared(num) <= 10)
	{
		num = add_complex_squared(num, c);
		iter++;
	}
	return (iter - 1);
}

void	draw_mandelbrot(t_data *img, t_complex min, \
t_complex max, int max_iterations)
{
	t_pixel		pixel;
	t_complex	c;

	pixel.x = 0;
	while (pixel.x < W_W)
	{
		pixel.y = 0;
		while (pixel.y < W_H)
		{
			c.real = min.real + (max.real - min.real) * pixel.x / W_W;
			c.imag = min.imag + (max.imag - min.imag) * pixel.y / W_H;
			pixel.iterations = mandelbrot(c, max_iterations);
			pixel.r = (int)(sin(0.08 * pixel.iterations) * 255);
			pixel.g = (int)(sin(0.03 * pixel.iterations) * 255);
			pixel.b = (int)(sin(0.02 * pixel.iterations) * 255);
			pixel.rgb = (pixel.r << 16) | (pixel.g << 8) | pixel.b;
			my_mlx_pixel_put(img, pixel.x, pixel.y, pixel.rgb);
			pixel.y++;
		}
		pixel.x++;
	}
}

int	close_window(void)
{
	exit(0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, W_W, W_H, "Mandelbrot");
	vars.img.img = mlx_new_image(vars.mlx, W_W, W_H);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, \
	&vars.img.line_length, &vars.img.endian);
//	draw_mandelbrot(&vars.img, (t_complex){-0.7437, 0.1317}, (t_complex){-0.7436, 0.1319}, 400);
  draw_mandelbrot(&vars.img, (t_complex){-2, -1.5}, (t_complex){1, 1.5}, 100);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
