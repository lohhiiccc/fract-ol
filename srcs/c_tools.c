/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:04:41 by lrio              #+#    #+#             */
/*   Updated: 2023/12/05 21:28:07 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

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
