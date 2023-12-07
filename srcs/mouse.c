/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <rio@student.42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:26:08 by lrio              #+#    #+#             */
/*   Updated: 2023/12/07 17:52:23 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse.h"
#include "libft.h"
#include "fractol.h"

int	mouse_hook(int keycode, t_vars vars)
{
	(void)vars;
	if(keycode == 5)
	{
		ft_putstr_fd("scroll down\n", 1);
		//draw_fractal(&vars.img, (t_complex){-2.5, -1}, (t_complex){1, 1}, 1000, &mandelbrot);
	}
	if(keycode == 4)
		ft_putstr_fd("scroll up\n", 1);
	if(keycode == 1)
		ft_putstr_fd("test", 1);
	return 0;
}