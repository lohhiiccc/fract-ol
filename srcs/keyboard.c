/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:29:33 by lrio              #+#    #+#             */
/*   Updated: 2023/12/16 04:57:16 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"
#include "keyboard.h"
#include "mlx.h"
#include "libft.h"
#include <limits.h>

void	esc(t_vars *vars)
{
	return ((void)close_window(vars));
}

key_func	get_key_func(int keycode)
{
	short		i;
	const t_key	key[] = {{A_UP, &arrow_up}, {A_LEFT, &arrow_left}, \
	{A_RIGHT, &arrow_right}, {A_DOWN, &arrow_down}, \
	{KEY_MINUS, &minus}, {KEY_PLUS, &plus}, {ESC, &esc}, \
	{SPACE, &space}, {-1, NULL}};

	i = 0;
	while (key[++i].key_id != -1)
		if (key[i - 1].key_id == keycode)
			return (key[i - 1].func);
	return (0);
}

int	keyboard(int key, t_vars *vars)
{
	key_func	key_f;

	key_f = get_key_func(key);
	if (key_f)
		key_f(vars);
	return (0);
}
