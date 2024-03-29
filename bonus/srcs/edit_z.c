/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:14:39 by lrio              #+#    #+#             */
/*   Updated: 2023/12/17 20:49:20 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"

void	rmzr(t_engine *vars)
{
	if (vars->fractal.fractal_func == &burning_ship)
		return ;
	vars->fractal.z.real -= 0.01;
	vars->fractal.needredraw = 1;
}

void	addzr(t_engine *vars)
{
	if (vars->fractal.fractal_func == &burning_ship)
		return ;
	vars->fractal.z.real += 0.01;
	vars->fractal.needredraw = 1;
}

void	rmzi(t_engine *vars)
{
	if (vars->fractal.fractal_func == &burning_ship)
		return ;
	vars->fractal.z.imag -= 0.01;
	vars->fractal.needredraw = 1;
}

void	addzi(t_engine *vars)
{
	if (vars->fractal.fractal_func == &burning_ship)
		return ;
	vars->fractal.z.imag += 0.01;
	vars->fractal.needredraw = 1;
}
