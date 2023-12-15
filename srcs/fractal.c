/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:30 by lrio              #+#    #+#             */
/*   Updated: 2023/12/14 15:01:31 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

int	burning_ship(t_complex c, int max_iterations)
{
	t_complex	num;
	int			iter;

	iter = 0;
	num.real = 0;
	num.imag = 0;
	while (iter < max_iterations && squared_norm(num) <= 4)
	{
		num = add_complex_squared(abs_complex(num), c);
		iter++;
	}
	return (iter);
}

int	julia(t_complex c, int max_iterations)
{
	t_complex	num;
	int			iter;

	iter = 0;
	num.real = -0.8;
	num.imag = 0.156;
	while (iter < max_iterations && squared_norm(c) <= 4)
	{
		c = add_complex(square_complex(c), num);
		iter++;
	}
	return (iter);
}

int	mandelbrot(t_complex c, int max_iterations)
{
	t_complex	num;
	int			iter;

	iter = 0;
	num.real = 0;
	num.imag = 0;
	while (iter < max_iterations && squared_norm(num) <= 4)
	{
		num = add_complex_squared(num, c);
		iter++;
	}
	return (iter);
}
