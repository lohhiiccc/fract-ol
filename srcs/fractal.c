/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:30 by lrio              #+#    #+#             */
/*   Updated: 2023/12/09 10:49:30 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "complex.h"

int burning_sheep(t_complex c, int max_iterations)
{
	t_complex	num;
	int iter;

	iter=0;
	num.real = 0;
	num.imag = 0;
	while (iter < max_iterations && squared_norm(num) <= 4)
	{

		num = add_complex_squared(abs_complex(num), c);
		iter++;
	}
	return iter - 1;
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
	return (iter - 1);
}