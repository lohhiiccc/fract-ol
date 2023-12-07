/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:59:23 by lrio              #+#    #+#             */
/*   Updated: 2023/12/07 17:59:34 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "complex.h"

#define W_W 1920
#define W_H 1080

typedef struct s_pixel {
	int x;
	int y;
	int iterations;
	int r;
	int g;
	int b;
	int rgb;
} t_pixel;

typedef struct	s_info {
	int			(*fractal_func)(t_complex, int);
	double		x;
	double 		y;
	t_com_coord comp;
	double		zoom_factor;
}				t_info;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_info 		info;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	t_complex min;
	t_complex max;
	int		max_iterations;

}				t_vars;

void	draw_fractal(t_data *img, t_com_coord comp, int max_iterations,int (*f)(t_complex, int));
int	mandelbrot(t_complex c, int max_iterations);
int burning_sheep(t_complex c, int max_iterations);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif