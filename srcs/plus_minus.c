/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 04:53:33 by lrio              #+#    #+#             */
/*   Updated: 2024/01/05 09:50:42 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"

void	minus(t_engine *vars)
{
	vars->fractal.max_iter *= 2;
	if (vars->fractal.max_iter > 40000)
		vars->fractal.max_iter = 40000;
	vars->fractal.needredraw = 1;
}

void	plus(t_engine *vars)
{
	vars->fractal.max_iter = vars->fractal.max_iter >> 1;
	if (vars->fractal.max_iter < 50)
		vars->fractal.max_iter = 50;
	vars->fractal.needredraw = 1;
}

void	space(t_engine *vars)
{
	if (vars->fractal.methode_type == DEFAULT)
		vars->fractal.methode_type = FAST;
	else
		vars->fractal.methode_type = DEFAULT;
	vars->fractal.needredraw = 2;
}
