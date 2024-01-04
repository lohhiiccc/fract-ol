/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:03:02 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 09:53:48 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include "keyboard.h"
#include <stdio.h>
#include "libft.h"

const char	*reversfunc(t_fractal_func func)
{
	int					i;
	const t_aliasfunc	funcs[3] = {{"julia", 6, &julia}, \
									{"mandelbrot", 11, &mandelbrot}, \
									{"burning_ship", 13, &burning_ship}};

	i = 0;
	while (funcs[i].fractal_func != func)
		i++;
	return (funcs[i].fractal_name);
}

double	*get_var_for_d(int i, t_vars *vars)
{
	if (i == 1)
		return (&(vars->info.x));
	if (i == 2)
		return (&(vars->info.y));
	if (i == 3)
		return (&(vars->info.zoom_factor));
	if (i == 5)
		return (&(vars->info.z.real));
	return (&(vars->info.z.imag));
}

int	*get_var_for_int(int i, t_vars *vars)
{
	if (i == 4)
		return (&(vars->info.max_iter));
	if (i == 7)
		return (&(vars->info.settings.colorset));
	return (&(vars->info.settings.d_color));
}

static void	putvars_fd(int i, t_vars *vars, int fd)
{
	if (i == 0)
		if (-1 == ft_putstr_fd((char *) \
				reversfunc(vars->info.fractal_func), fd))
			exit(close_window(vars));
	if (i == 4 || i == 8 || i == 7)
		ft_putnbr_fd(*get_var_for_int(i, vars), fd);
	if ((i >= 1 && i <= 3) || i == 5 || i == 6)
		if (-1 == ft_putfloat_fd(*get_var_for_d(i, vars), fd))
			exit(close_window(vars));
}

void	save(t_vars *vars)
{
	const char	*f_format[] = {"fr:", "x:", "y:", "zoom:", \
		"iter:", "c.r:", "c.i:", "color_set:", "d_color:", NULL};
	int			i;
	int			fd;

	fd = open("./fractal.save", O_WRONLY);
	if (fd < 0)
		exit(close_window(vars));
	i = 0;
	while (i <= 8)
	{
		if (-1 == ft_putstr_fd((char *) f_format[i], fd))
			exit(close_window(vars));
		putvars_fd(i, vars, fd);
		if (-1 == write(fd, "\n", 1))
			exit(close_window(vars));
		i++;
	}
	close(fd);
}
