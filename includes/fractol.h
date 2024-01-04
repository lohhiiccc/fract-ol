/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:54 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 17:43:54 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <stdint.h>
# include "complex.h"

# define W_W 1920
# define W_H 1080

enum e_method_type {
	DEFAULT = 0,
	FAST = 1,
	FULL = 2,
};

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
	int			d_color;
}				t_settings;

typedef int	(*t_fractal_func)(t_complex z, t_complex c, int);

typedef struct s_aliasfunc
{
	const char		*fractal_name;
	short			len;
	t_fractal_func	fractal_func;
}					t_aliasfunc;

typedef struct s_fractal
{
	t_fractal_func		fractal_func;
	int methode_type;
	double				x;
	double				y;
	double				zoom_factor;
	int					max_iter;
	t_complex			z;
	t_com_coord			comp;
	t_settings			settings;
	short				needredraw;
}						t_fractal;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_engine
{
	void			*mlx;
	void			*win;
	unsigned int	line_counter;
	pthread_mutex_t	mutex_line_counter;
	pthread_mutex_t	mutex_img;
	t_img			img;
	t_fractal		fractal;
}				t_engine;

t_complex		getcomplex(t_pixel pixel, t_fractal info);
t_fractal		calc_coord(t_fractal init_v);
int				make_pixel(t_engine *vars, \
t_complex z, t_complex c, t_pixel pixel);
int				parsing(const char *path, t_engine *vars, void *func);
t_fractal_func	get_func(const char *name);
int				julia(t_complex z, t_complex c, int max_iterations);
int				close_window(t_engine *vars);
void			even_pixel(uint32_t *img_ptr);
void			odd_pixel(uint32_t *img_ptr);
void			*fast_draw(void *engine);
void			*draw_fractal(void *vars);
int				mandelbrot(t_complex z, t_complex c, int max_iterations);
int				burning_ship(t_complex z, t_complex c, int max_iterations);
#endif