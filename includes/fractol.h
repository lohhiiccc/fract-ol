/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:54 by lrio              #+#    #+#             */
/*   Updated: 2023/12/09 17:04:11 by lrio             ###   ########.fr       */
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
}				t_data;

typedef struct	s_vars {
	void	    *mlx;
	void	    *win;
	t_data  	img;
    t_info 		info;
}				t_vars;

t_com_coord zoom(t_com_coord c, double x, double y, double *zoom, int i);
void make_image(double x, double y, double zoom, t_com_coord comp,t_vars *vars);
void draw_fractal(t_vars *vars, int max_iterations);
int	mandelbrot(t_complex c, int max_iterations);
int burning_sheep(t_complex c, int max_iterations);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif