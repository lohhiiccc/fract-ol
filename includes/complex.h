/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:05:23 by lrio              #+#    #+#             */
/*   Updated: 2023/12/07 14:47:31 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COMPLEX_H
# define FRACTOL_COMPLEX_H

typedef struct s_complex {
	double	real;
	double	imag;
}			t_complex;

typedef struct s_com_coord {
	t_complex min;
	t_complex max;
}		t_com_coord;

t_complex	add_f2complex(t_complex c, double n);
t_complex multiply_complex(t_complex, int num);
t_complex	abs_complex(t_complex c);
double magnitude_squared(t_complex c);
t_complex square_complex(t_complex c);
t_complex add_complex_squared(t_complex a, t_complex b);
t_complex add_complex(t_complex a, t_complex b);

#endif //FRACTOL_COMPLEX_H
