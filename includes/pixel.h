/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:12:09 by lrio              #+#    #+#             */
/*   Updated: 2023/12/12 14:39:22 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIXEL_H
#define PIXEL_H
#include <stddef.h>
#include <stdint.h>

typedef struct s_rgb{
	uint32_t 	r;
	uint32_t 	g;
	uint32_t 	b;
	uint32_t 	*addr;
}	t_rgb;

typedef struct s_around_p{
	t_rgb a;
	t_rgb b;
	t_rgb c;
	t_rgb d;
}	t_around_p;


typedef struct s_coord{
	size_t x;
	size_t y;
}	t_coord;

t_rgb uncolor(uint32_t color);
t_around_p uncolorall(t_around_p area);
t_rgb average_rgb(t_around_p around);
uint32_t get_color(t_around_p around);
#endif
