/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:26 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 13:09:37 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "libft.h"
#include "mouse.h"
#include "mlx_init.h"
#define FR_LST \
"./fractol <julia/mandelbrot/burning_ship> \nor fractal.save if file exist"
#include "threads.h"


int	render_img(t_engine *vars)
{
	if (vars->fractal.needredraw == 1 || vars->fractal.needredraw == 2)
	{
		if (vars->fractal.needredraw == 1)
			inti_thread(&draw_fractal, vars);
		else if (vars->fractal.needredraw == 2)
			inti_thread(&draw_fractal, vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
//			fast_draw(vars);
	return (0);
}

t_fractal_func	get_func(const char *name)
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

int	main(int argc, char **argv)
{
	t_engine	vars;
	void	*func;
	int		tmp;

	pthread_mutex_init(&vars.mutex_line_counter, NULL);
	pthread_mutex_init(&vars.mutex_img, NULL);
	tmp = 0;
	vars.fractal.z = (t_complex){0, 0};
	vars.fractal.comp = (t_com_coord){(t_complex){-2.5, -1.5}, \
	(t_complex){2.5, 1.5}};
	func = NULL;
	if (!(argc != 2))
		func = get_func(argv[1]);
	vars.fractal = (t_fractal){func, 0, 0, 0, 1, 100, vars.fractal.z, \
	vars.fractal.comp, (t_settings){1, 1}, 1};
	if (func == NULL)
		tmp = parsing(argv[1], &vars, func);
	if (argc < 2 || tmp == -1)
		return (ft_putstr_fd(FR_LST, 2), -1);
	if (argc <= 2 && func == &julia)
		vars.fractal.z = (t_complex){0.285, 0.01};
	if (-1 == initvar(&vars))
		return (0);
	loop(&vars);
	destroy_mlx(&vars);
	return (0);
}
