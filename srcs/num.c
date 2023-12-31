/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:37:49 by lrio              #+#    #+#             */
/*   Updated: 2023/12/31 18:04:11 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"

void	keythree(t_vars *vars)
{
	if (vars->info.settings.colorset == 3)
		return ;
	vars->info.settings.colorset = 3;
	vars->info.needredraw = 2;
}

void	keytwo(t_vars *vars)
{
	if (vars->info.settings.colorset == 2)
		return ;
	vars->info.settings.colorset = 2;
	vars->info.needredraw = 2;
}

void	keyone(t_vars *vars)
{
	if (vars->info.settings.colorset == 1)
		return ;
	vars->info.settings.colorset = 1;
	vars->info.needredraw = 2;
}