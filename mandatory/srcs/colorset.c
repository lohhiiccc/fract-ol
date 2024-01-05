/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:47:15 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 09:44:27 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

static int	make_color(t_pixel pixel)
{
	return (((int)pixel.r << 16) | ((int)pixel.g << 8) | (int)pixel.b);
}

int	colorset_one(t_pixel pixel)
{
	pixel.r = (int)(sin(0.036 * (pixel.iterations) + 4) * 130 + 25);
	pixel.g = (int)(sin(0.013 * (pixel.iterations) + 2) * 130 + 25);
	pixel.b = (int)(sin(0.01 * (pixel.iterations) + 1) * 130 + 25);
	return (make_color(pixel));
}

int	colorset_two(t_pixel pixel)
{
	pixel.r = (int)(sin(0.036 * (pixel.iterations)) * 130);
	pixel.g = (int)(sin(0.013 * (pixel.iterations)) * 130);
	pixel.b = (int)(sin(0.01 * (pixel.iterations)) * 130);
	return (make_color(pixel));
}

int	colorset_three(t_pixel pixel)
{
	pixel.r = (int)(sin(0.00 * (pixel.iterations)) * 130);
	pixel.g = (int)(sin(0.083 * (pixel.iterations)) * 130);
	pixel.b = (int)(sin(0.01 * (pixel.iterations)) * 130);
	return (make_color(pixel));
}

int	colorset_four(t_pixel pixel)
{
	pixel.r = (int)(sin(0.05 * pixel.iterations) * 127);
	pixel.g = (int)(sin(0.03 * pixel.iterations) * 255);
	pixel.b = (int)(sin(0.01 * pixel.iterations) * 127);
	return (make_color(pixel));
}
