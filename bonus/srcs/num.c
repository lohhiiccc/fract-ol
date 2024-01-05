/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:37:49 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 09:42:19 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"

void	keythree(t_engine *vars)
{
	if (vars->fractal.settings.colorset == 3)
		return ;
	vars->fractal.settings.colorset = 3;
	vars->fractal.needredraw = 2;
}

void	keytwo(t_engine *vars)
{
	if (vars->fractal.settings.colorset == 2)
		return ;
	vars->fractal.settings.colorset = 2;
	vars->fractal.needredraw = 2;
}

void	keyone(t_engine *vars)
{
	if (vars->fractal.settings.colorset == 1)
		return ;
	vars->fractal.settings.colorset = 1;
	vars->fractal.needredraw = 2;
}

void	keyfour(t_engine *vars)
{
	if (vars->fractal.settings.colorset == 4)
		return ;
	vars->fractal.settings.colorset = 4;
	vars->fractal.needredraw = 2;
}
