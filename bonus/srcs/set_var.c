/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:08:51 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 12:42:21 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_var.h"

void	set_vinfo_int(t_engine *vars, int num, int i)
{
	if (i == 4)
		vars->fractal.max_iter = num;
	if (i == 7)
		vars->fractal.settings.colorset = num;
	if (i == 8)
		vars->fractal.settings.d_color = num;
}

void	set_vinfo_double(t_engine *vars, double num, int i)
{
	if (i == 1)
		vars->fractal.x = num;
	else if (i == 2)
		vars->fractal.y = num;
	else if (i == 3)
		vars->fractal.zoom_factor = num;
	else if (i == 5)
		vars->fractal.z.real = num;
	else if (i == 6)
		vars->fractal.z.imag = num;
}
