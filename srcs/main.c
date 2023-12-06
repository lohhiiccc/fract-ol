/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:39:03 by lrio              #+#    #+#             */
/*   Updated: 2023/12/06 16:28:23 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fractol.h"
#include "complex.h"
#include <math.h>

#define W_W 1920
#define W_H 1080

int burning_sheep(t_complex c, int max_iterations)
{
	t_complex	num;
	int iter;

	iter=0;
	num.real = 0;
	num.imag = 0;
	while (iter < max_iterations && magnitude_squared(num) <= 100)
	{

		num = add_complex_squared(abs_complex(num), c);
		iter++;
	}
	return iter - 1;
}

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

void	draw_fractal(t_data *img, t_complex min, \
t_complex max, int max_iterations,int (*f)(t_complex, int))
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
			pixel.iterations = f(c, max_iterations);
			pixel.r = (int)(sin(0.05 * pixel.iterations) * 0);
			pixel.g = (int)(sin(0.03 * pixel.iterations) * 0);
			pixel.b = (int)(sin(0.1 * pixel.iterations) * 225);
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

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, W_W, W_H, "Mandelbrot");
	vars.img.img = mlx_new_image(vars.mlx, W_W, W_H);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, \
	&vars.img.line_length, &vars.img.endian);
	//draw_mandelbrot(&vars.img, (t_complex){-0.7437, 0.1317}, (t_complex){-0.7436, 0.1319}, 4000);
	//draw_mandelbrot(&vars.img, (t_complex){-2, -1.5}, (t_complex){2, 1.5}, 100);
	//left,top, right, bottom

	if(ft_atoi(argv[1]) == 1)
		draw_fractal(&vars.img, (t_complex){-2.5, -1}, (t_complex){1, 1}, 100, &mandelbrot);
	else
		draw_fractal(&vars.img, (t_complex){-2.5, -1}, (t_complex){1, 1}, 100, &burning_sheep);
	//draw_mandelbrot(&vars.img, (t_complex){-0.807283201245, -0.179474552794}, (t_complex){-0.798415461248, -0.176052340906}, 4400, &mandelbrot);
	ft_putstr_fd("ok", 1);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
