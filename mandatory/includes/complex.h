/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:49:58 by lrio              #+#    #+#             */
/*   Updated: 2024/01/01 17:36:37 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_com_coord
{
	t_complex	min;
	t_complex	max;
}				t_com_coord;

t_complex	abs_complex(t_complex c);
double		squared_norm(t_complex c);
t_complex	square_complex(t_complex c);
t_complex	add_complex_squared(t_complex a, t_complex b);
t_complex	add_complex(t_complex a, t_complex b);

#endif
