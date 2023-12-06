/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:05:23 by lrio              #+#    #+#             */
/*   Updated: 2023/12/06 12:59:23 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COMPLEX_H
# define FRACTOL_COMPLEX_H

typedef struct s_complex {
	double	real;
	double	imag;
}			t_complex;

t_complex	abs_complex(t_complex c);
double magnitude_squared(t_complex c);
t_complex square_complex(t_complex c);
t_complex add_complex_squared(t_complex a, t_complex b);
t_complex add_complex(t_complex a, t_complex b);

#endif //FRACTOL_COMPLEX_H
