/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:04:41 by lrio              #+#    #+#             */
/*   Updated: 2023/12/07 14:36:46 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	add_f2complex(t_complex c, double n)
{
	t_complex res;

	res.real = c.real + n;
	res.imag = c.imag + n;
	return res;
}

t_complex	add_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return (result);
}

double	magnitude_squared(t_complex c)
{
	return (c.real * c.real + c.imag * c.imag);
}

t_complex	abs_complex(t_complex c)
{
	t_complex	result;
	result.real = c.real;
	result.imag = c.imag;
	if(c.real < 0)
		result.real = -c.real;
	if(c.imag < 0)
		result.imag = -c.imag;
	return (result);
}

t_complex	square_complex(t_complex c)
{
	t_complex	result;

	result.real = c.real * c.real - c.imag * c.imag;
	result.imag = 2 * c.real * c.imag;
	return (result);
}

t_complex	add_complex_squared(t_complex a, t_complex b)
{
	return (add_complex(square_complex(a), b));
}

t_complex multiply_complex(t_complex c, int num)
{
	t_complex result;

	result.real = c.real * num;
	result.imag = c.imag * num;
	return result;
}
