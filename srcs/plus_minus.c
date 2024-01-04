/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 04:53:33 by lrio              #+#    #+#             */
/*   Updated: 2024/01/03 17:15:00 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "keyboard.h"
#include <limits.h>

void	minus(t_engine *vars)
{
	vars->fractal.max_iter *= 2;
	if (vars->fractal.max_iter > 1600)
		vars->fractal.max_iter = 1600;
	vars->fractal.needredraw = 1;
}

void	plus(t_engine *vars)
{
	vars->fractal.max_iter /= 2;
	if (vars->fractal.max_iter < 50)
		vars->fractal.max_iter = 50;
	vars->fractal.needredraw = 1;
}

void	space(t_engine *vars)
{
	if (vars->fractal.methode_type == 0)
		vars->fractal.methode_type = 1;
	else
		vars->fractal.methode_type = 0;
	vars->fractal.needredraw = 2;
}
