/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 04:53:33 by lrio              #+#    #+#             */
/*   Updated: 2023/12/16 04:58:32 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "keyboard.h"
#include <limits.h>

void	minus(t_vars *vars)
{
	if (vars->info.max_iter * 2 < INT_MIN)
		ft_putstr_fd("error to much iteration", 1);
	else
		vars->info.max_iter *= 2;
}

void	plus(t_vars *vars)
{
	vars->info.max_iter /= 2;
	if (vars->info.max_iter < 50)
		vars->info.max_iter = 50;
	vars->info.needredraw = 1;
}

void	space(t_vars *vars)
{
	if (vars->info.methode_type == 0)
		vars->info.methode_type = 1;
	else
		vars->info.methode_type = 0;
	vars->info.needredraw = 2;
}
