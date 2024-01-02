/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:26 by lrio              #+#    #+#             */
/*   Updated: 2024/01/02 12:38:26 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "mlx.h"
#include "libft.h"
#include <math.h>
#include "mouse.h"
#include "get_next_line.h"
#include "keyboard.h"
#define FR_LST "./fractol <julia/mandelbrot/burning_ship>"

int	close_window(t_vars *vars)
{
	return (mlx_loop_end(vars->mlx));
}

int	render_img(t_vars *vars)
{
	if (vars->info.needredraw == 1 || vars->info.needredraw == 2)
	{
		if (vars->info.needredraw == 1)
			fast_draw(vars);
		else if (vars->info.needredraw == 2)
			draw_fractal(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	}
	return (0);
}

void	loop(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_key_hook(vars->win, keyboard, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_loop_hook(vars->mlx, render_img, vars);
	mlx_loop(vars->mlx);
}

static t_fractal_func	get_func(const char *name)
{
	short				i;
	const t_aliasfunc	funcs[3] = {{"julia", 6, &julia}, \
									{"mandelbrot", 11, &mandelbrot}, \
									{"burning_ship", 13, &burning_ship}};

	i = 0;
	while (++i <= 3)
		if (!ft_strncmp(name, funcs[i - 1].fractal_name, funcs[i - 1].len))
			return (funcs[i - 1].fractal_func);
	return (NULL);
}

int initvar(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (ft_putstr_fd("error", 2), -1);
	vars->win = mlx_new_window(vars->mlx, W_W, W_H, "fractol");
	vars->data.img = mlx_new_image(vars->mlx, W_W, W_H);
	vars->data.addr = mlx_get_data_addr(vars->data.img, \
	&vars->data.bits_per_pixel, &vars->data.line_length, &vars->data.endian);
	return 0;
}

void destroy_mlx(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

double ft_strtod(char *str)
{
	double	res;
	int 	is_null;
	int 	is_neg;

	is_neg = 0;
	if (str[0] == '-')
		is_neg = 1;
	if(!ft_strncmp(str + is_neg, "0.000000000000000", 15))
		return (0.0);
	is_null = 0;
	if(str[is_neg] == '0')
	{
		is_null = 1;
		if(str[is_neg] == '-')
			str[1+is_neg] = '1';
		else
			str[is_neg] = '1';
	}
	res = ft_atoi(str + is_neg) + ft_atol(str + 2 + is_neg) / pow(10, 15);
	if (is_null && !ft_strncmp(str + is_neg + 2, "000000000000000", 15))
		res -= 0.1;
	if(str[is_neg] != ft_atoi(str + is_neg) && is_null)
		res -= ft_atoi(str +is_neg);
	if (is_neg)
		res = -res;
	return res;
}

void	set_vars(t_vars *vars,double num,int i)
{
	printf("\n--\nfloat%f\n---\n",num);
	if(i == 1)
		vars->info.x = num;
	if(i == 2)
		vars->info.y = num;
	if(i == 3)
		vars->info.zoom_factor = num;
}

int parsing(const char *path, t_vars *vars, void *func)
{
	const char	*fileformat[] = {"fr:","x:","y:","zoom:","iter:","z:","color_set:","d_color",NULL};
	int			fd;
	char		*line;
	int 		i;

	vars->info.z = (t_complex){0,0};
	vars->info.needredraw = 1;
	vars->info.methode_type = 1;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (i <= 7)
	{
		line = get_next_line(fd);
		if(line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strncmp(line, fileformat[i], ft_strlen(fileformat[i])))
			return (printf("casee\n"), -1);
		if (i == 0)
		{
			func = get_func(line + ft_strlen(fileformat[0]));
			if(func == NULL)
				return (free(line), -1);
			vars->info.fractal_func = func;
		}
		if (i >= 1 && i <= 3)
			set_vars(vars, ft_strtod(line + ft_strlen(fileformat[i])), i);
		if (i == 4)
			vars->info.max_iter = ft_atoi(line + ft_strlen(fileformat[i]));
		if (i == 5)
			vars->info.z = (t_complex){ft_strtod(line + ft_strlen(fileformat[i])), ft_strtod(line + ft_strlen(fileformat[i]) + ft_strclen(line + ft_strlen(fileformat[i]), ':'))};
		if (i == 6)
			vars->info.settings.colorset = ft_atoi(line + ft_strlen(fileformat[i]));
		if (i == 7)
			vars->info.settings.d_color = ft_atoi(line + ft_strlen(fileformat[i]) + 1);
		i++;
		free(line);
	}
	if(vars->info.zoom_factor == 0)
		vars->info.zoom_factor = 1;
	close(fd);
	return 0;
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	void	*func;
	int tmp = 0;
	vars.info.z = (t_complex){0, 0};
	vars.info.comp = (t_com_coord ){(t_complex){-2.5, -1.5}, (t_complex){2.5, 1.5}};
	func = NULL;
	if (argc >= 2)
		func = get_func(argv[1]);
	vars.info = (t_info){func, 0, 0, 0, 1, 100, vars.info.z, vars.info.comp, (t_settings){1, 1}, 1};
	if (func == NULL)
		tmp = parsing(argv[1], &vars, func);
	if (argc < 2 || tmp == -1)
		return (ft_putstr_fd(FR_LST, 2), -1);
	if (argc <= 2 && func == &julia)
		vars.info.z = (t_complex){-0.8, 0.156};
	if(-1 == initvar(&vars))
		return 0;
	loop(&vars);
	destroy_mlx(&vars);
	return (0);
}
