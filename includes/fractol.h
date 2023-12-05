/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:59:23 by lrio              #+#    #+#             */
/*   Updated: 2023/12/05 21:23:26 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "complex.h"

typedef struct s_pixel {
	int x;
	int y;
	int iterations;
	int r;
	int g;
	int b;
	int rgb;
} t_pixel;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	t_complex min;
	t_complex max;
	int		max_iterations;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif