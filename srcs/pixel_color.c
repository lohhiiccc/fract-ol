/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:14:14 by lrio              #+#    #+#             */
/*   Updated: 2023/12/12 13:14:14 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel.h"

t_rgb uncolor(uint32_t color)
{
	t_rgb c;
	c.r = (color >> 16) & 0xFF;
	c.g = (color >> 8) & 0xFF;
	c.b = (color & 0xFF);

	return c;
}

t_around_p uncolorall(t_around_p area)
{
	area.a = uncolor(*area.a.addr);
	area.b = uncolor(*area.b.addr);
	area.c = uncolor(*area.c.addr);
	area.d = uncolor(*area.d.addr);
	return (area);
}

t_rgb average_rgb(t_around_p around) {
	t_rgb avg;
	avg.r = (around.a.r + around.b.r + around.c.r + around.d.r) >> 2;
	avg.g = (around.a.g + around.b.g + around.c.g + around.d.g) >> 2;
	avg.b = (around.a.b + around.b.b + around.c.b + around.d.b) >> 2;
	return avg;
}

uint32_t get_color(t_around_p around)
{
	t_rgb avg = average_rgb(around);
	return ((avg.r << 16) | (avg.g << 8) | avg.b);
}
