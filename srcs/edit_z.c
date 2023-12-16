/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:14:39 by lrio              #+#    #+#             */
/*   Updated: 2023/12/16 07:23:29 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"

void	rmzr(t_vars *vars)
{
	if (vars->info.fractal_func == &burning_ship)
		return ;
	vars->info.z.real -= 0.1;
	vars->info.needredraw = 1;
}

void	addzr(t_vars *vars)
{
	if (vars->info.fractal_func == &burning_ship)
		return ;
	vars->info.z.real += 0.1;
	vars->info.needredraw = 1;
}

void	rmzi(t_vars *vars)
{
	if (vars->info.fractal_func == &burning_ship)
		return ;
	vars->info.z.imag -= 0.1;
	vars->info.needredraw = 1;
}

void	addzi(t_vars *vars)
{
	if (vars->info.fractal_func == &burning_ship)
		return ;
	vars->info.z.imag += 0.1;
	vars->info.needredraw = 1;
}
