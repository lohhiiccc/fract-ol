/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:08:51 by lrio              #+#    #+#             */
/*   Updated: 2024/01/02 15:10:30 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_var.h"

void	set_vinfo_int(t_vars *vars, int num, int i)
{
	if (i == 4)
		vars->info.max_iter = num;
	if (i == 7)
		vars->info.settings.colorset = num;
	if (i == 8)
		vars->info.settings.d_color = num;
}

void	set_vinfo_double(t_vars *vars, double num, int i)
{
	if (i == 1)
		vars->info.x = num;
	else if (i == 2)
		vars->info.y = num;
	else if (i == 3)
		vars->info.zoom_factor = num;
	else if (i == 5)
		vars->info.z.real = num;
	else if (i == 6)
		vars->info.z.imag = num;
}
