/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:54 by lrio              #+#    #+#             */
/*   Updated: 2024/01/02 18:02:43 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include "complex.h"

//# define W_W 2560
//# define W_H 1440

# define W_W 1920
# define W_H 1080

typedef struct s_pixel
{
	int		x;
	int		y;
	int		iterations;
	short	r;
	short	g;
	short	b;
}			t_pixel;

typedef struct s_settings
{
	int			colorset;
	int 		d_color;
}				t_settings;

typedef int	(*t_fractal_func)(t_complex z, t_complex c, int);

typedef struct s_aliasfunc
{
	const char		*fractal_name;
	short			len;
	t_fractal_func	fractal_func;
}					t_aliasfunc;

typedef struct s_info
{
	t_fractal_func		fractal_func;
	int					methode_type;
	double				x;
	double				y;
	double				zoom_factor;
	int					max_iter;
	t_complex			z;
	t_com_coord			comp;
	t_settings			settings;
	short				needredraw;
}						t_info;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		data;
	t_info		info;
}				t_vars;

int				parsing(const char *path, t_vars *vars, void *func);
t_fractal_func	get_func(const char *name);
int				julia(t_complex z, t_complex c, int max_iterations);
int				close_window(t_vars *vars);
void			even_pixel(uint32_t *img_ptr);
void			odd_pixel(uint32_t *img_ptr);
void			fast_draw(t_vars *vars);
void			draw_fractal(t_vars *vars);
int				mandelbrot(t_complex z, t_complex c, int max_iterations);
int				burning_ship(t_complex z, t_complex c, int max_iterations);
#endif