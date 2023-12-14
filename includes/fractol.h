/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:54 by lrio              #+#    #+#             */
/*   Updated: 2023/12/14 12:56:34 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdint.h>
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
} t_pixel;

typedef struct	s_info {
	int			(*fractal_func)(t_complex, int);
	int			methode_type;
	double		x;
	double 		y;
	double		zoom_factor;
    int			max_iter;
    t_com_coord comp;
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
	t_data  	data;
    t_info 		info;
}				t_vars;

void	even_pixel(uint32_t *img_ptr);
void	odd_pixel(uint32_t *img_ptr);
void	fast_draw(t_vars *vars);
void draw_fractal(t_vars *vars);
int	mandelbrot(t_complex c, int max_iterations);
int burning_ship(t_complex c, int max_iterations);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif