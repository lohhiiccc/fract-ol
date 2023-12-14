/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilinear_interpolation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:54:21 by lrio              #+#    #+#             */
/*   Updated: 2023/12/14 13:10:11 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel.h"
#include "keyboard.h"

static t_around_p	getpixel_corner(uint32_t *img_ptr, t_coord coord)
{
	t_around_p	c;

	c.a.addr = img_ptr + (coord.y - 1) * W_W + coord.x - 1;
	c.b.addr = img_ptr + (coord.y - 1) * W_W + coord.x + 1;
	c.c.addr = img_ptr + (coord.y + 1) * W_W + coord.x - 1;
	c.d.addr = img_ptr + (coord.y + 1) * W_W + coord.x + 1;
	return (c);
}

static t_around_p	getpixel_cross(uint32_t *img_ptr, \
							uint32_t *center_pixel, t_coord coord)
{
	t_around_p	c;

	c.a.addr = center_pixel - 1;
	c.b.addr = center_pixel + 1;
	c.c.addr = img_ptr + (coord.y - 1) * W_W + coord.x;
	c.d.addr = img_ptr + (coord.y + 1) * W_W + coord.x;
	return (c);
}

void	even_pixel(uint32_t *img_ptr)
{
	t_coord		coord;
	uint32_t	*center_pixel;

	coord.y = 1;
	while (coord.y < W_H - 1)
	{
		coord.x = 1;
		while (coord.x < W_W - 1)
		{
			center_pixel = img_ptr + coord.y * W_W + coord.x;
			if (*center_pixel == 1)
				*center_pixel = (get_color(uncolorall(\
				getpixel_cross(img_ptr, center_pixel, coord))));
			coord.x++;
		}
		coord.y++;
	}
}

void	odd_pixel(uint32_t *img_ptr)
{
	t_coord		coord;
	uint32_t	*center_pixel;

	coord.y = 1;
	while (coord.y < W_H - 1)
	{
		coord.x = 1;
		while (coord.x < W_W - 1)
		{
			if (coord.x % 2 == 1 || coord.y % 2 == 1)
			{
				center_pixel = img_ptr + coord.y * W_W + coord.x;
				*center_pixel = (get_color(uncolorall(\
				(getpixel_corner(img_ptr, coord)))));
			}
			coord.x += 1;
		}
		coord.y += 1;
	}
}
