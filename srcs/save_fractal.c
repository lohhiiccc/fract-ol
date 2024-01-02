/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:03:02 by lrio              #+#    #+#             */
/*   Updated: 2024/01/02 18:21:00 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include "keyboard.h"
#include <math.h>
#include "libft.h"

const char *reversfunc(t_fractal_func func)
{
	int 				i;
	const t_aliasfunc	funcs[3] = {{"julia", 6, &julia}, \
									{"mandelbrot", 11, &mandelbrot}, \
									{"burning_ship", 13, &burning_ship}};

	i = 0;
	while (funcs[i].fractal_func != func)
		i++;
	return (funcs[i].fractal_name);
}

double *get_var_for_d(int i, t_vars *vars)
{
	if (i == 1)
		return &(vars->info.x);
	if (i == 2)
		return &(vars->info.y);
	if (i == 3)
		return &(vars->info.zoom_factor);
	if (i == 5)
		return &(vars->info.z.real);
	return &(vars->info.z.imag);
}

int *get_var_for_int(int i, t_vars *vars)
{
		if ( i == 4)
			return &(vars->info.max_iter);
		if (i == 7)
			return &(vars->info.settings.colorset);
		return &(vars->info.settings.d_color);
}

int ft_putf_fd(double num, int fd)
{
	int tmp;
	tmp = (int)((double)num - (int)num) * pow(10, 15);
	if (-1 == ft_putnbr_fd((int)num, fd))
		return -1;
	if (-1 == ft_putnbr_fd(tmp, fd))
		return -1;
	return 0;
}

void	save(t_vars *vars)
{
	(void)vars;
	const char	*f_format[] = {"fr:", "x:", "y:", "zoom:", \
		"iter:", "z.r:", "z.i:", "color_set:", "d_color:", NULL};
	int			i;
	int			fd;

	fd = open("./file.fractal", O_RDWR);
	if (fd < 0) //penser a check erno
		return ;
	i = 0;
	while (i <= 8) {
		if (-1 == ft_putstr_fd((char *) f_format[i], fd))
			return;
		if (i == 0)
			if (-1 == ft_putstr_fd((char *) reversfunc(vars->info.fractal_func), fd))
				return;
		if (i == 4 || i == 8 || i == 7)
			ft_putnbr_fd(*get_var_for_int(i, vars), fd);
		if ((i >= 1 && i <= 3) || i == 5 || i == 6)
			ft_putf_fd(*get_var_for_d(i, vars), fd);
		if (-1 == write(fd, "\n", 1))
			return ;
		i++;
	}
	close(fd);
}
