/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:54:35 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 18:29:46 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "set_var.h"

int	bypass_zero(char *str, int is_neg)
{
	int	is_null;

	is_null = 0;
	if (str[is_neg] == '0')
	{
		is_null = 1;
		if (str[is_neg] == '-')
			str[1 + is_neg] = '1';
		else
			str[is_neg] = '1';
	}
	return (is_null);
}

double	ft_strtod(char *str)
{
	double	res;
	int		is_null;
	int		is_neg;

	is_neg = 0;
	is_null = 0;
	if (str[0] == '-')
		is_neg = 1;
	if (!ft_strncmp(str + is_neg, "0.000000000000000", 15))
		return (0.0);
	is_null = bypass_zero(str, is_neg);
	res = ft_atoi(str + is_neg) + ft_atol(str + 2 + is_neg) / pow(10, 15);
	if (is_null && !ft_strncmp(str + is_neg + 2, "000000000000000", 15))
		res -= 0.1;
	if (str[is_neg] != ft_atoi(str + is_neg) && is_null)
		res -= ft_atoi(str + is_neg);
	if (is_neg)
		res = -res;
	return (res);
}

static void	set_vinfo(t_engine *vars, int i, const char **f_format, char *line)
{
	if ((i >= 1 && i <= 3) || (i >= 5 && i <= 6))
		set_vinfo_double(vars, ft_strtod(line + ft_strlen(f_format[i])), i);
	else
		set_vinfo_int(vars, ft_atoi(line + ft_strlen(f_format[i])), i);
}

int	set_parsing_var(t_engine *vars, int fd, void *func)
{
	const char	*f_format[] = {"fr:", "x:", "y:", "zoom:", \
		"iter:", "c.r:", "c.i:", "color_set:", "d_color:", NULL};
	char		*line;
	int			i;

	i = 0;
	while (++i <= 8)
	{
		line = get_next_line(fd);
		if (!line)
			return (-1);
		line[ft_strlen(line) - 1] = '\0';
		if (ft_strncmp(line, f_format[i - 1], ft_strlen(f_format[i - 1])))
			return (free(line), -1);
		if (i - 1 == 0)
		{
			func = get_func(line + ft_strlen(f_format[0]));
			if (func == NULL)
				return (free(line), -1);
			vars->fractal.fractal_func = func;
		}
		set_vinfo(vars, i - 1, f_format, line);
		free(line);
	}
	return (0);
}

int	parsing(const char *path, t_engine *vars, void *func)
{
	int			fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (set_parsing_var(vars, fd, func) == -1)
		return (close(fd), -1);
	if (vars->fractal.zoom_factor == 0)
		vars->fractal.zoom_factor = 1;
	close(fd);
	return (0);
}
