/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:30 by lrio              #+#    #+#             */
/*   Updated: 2023/12/16 06:59:11 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "complex.h"

int burning_ship(t_complex z, t_complex c, int max_iterations)
{
	int			iter;

	iter = 0;
	while (iter < max_iterations && squared_norm(z) <= 4)
	{
		z = add_complex_squared(abs_complex(z), c);
		iter++;
	}
	return (iter);
}

int julia(t_complex z, t_complex c, int max_iterations)
{
	int			iter;

	iter = 0;
	while (iter < max_iterations && squared_norm(c) <= 4)
	{
		c = add_complex_squared(c, z);
		iter++;
	}
	return (iter);
}

int mandelbrot(t_complex z, t_complex c, int max_iterations)
{
	int			iter;

	iter = 0;
	while (iter < max_iterations && squared_norm(z) <= 4)
	{
		z = add_complex_squared(z, c);
		iter++;
	}
	return (iter);
}
