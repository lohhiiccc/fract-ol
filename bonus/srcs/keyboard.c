/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:29:33 by lrio              #+#    #+#             */
/*   Updated: 2024/01/05 12:38:56 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"

static void	esc(t_engine *vars)
{
	return ((void)close_window(vars));
}

static void	del(t_engine *vars)
{
	if (vars->fractal.settings.d_color == 1)
		vars->fractal.settings.d_color = 0;
	else
		vars->fractal.settings.d_color = 1;
	vars->fractal.needredraw = 1;
}

void	fone(t_engine *vars)
{
	save(vars);
	return ;
}

static t_key_func	get_key_func(int keycode)
{
	unsigned char	i;
	const t_key		key[] = {{A_UP, &arrow_up}, {A_LEFT, &arrow_left}, \
							{A_RIGHT, &arrow_right}, {A_DOWN, &arrow_down}, \
							{KEY_MINUS, &minus}, {KEY_PLUS, &plus}, \
							{ESC, &esc}, {SPACE, &space}, {DEL, &del}, \
							{CR_2, &addzr}, {CR_1, &rmzr}, \
							{PLUS_DIGIT, &addzi}, {MINUS_DIGIT, &rmzi}, \
							{ONE, &keyone}, {TWO, &keytwo}, {THREE, &keythree}, \
							{FOUR, &keyfour}, {NP_ONE, &fone}, {-1, NULL}};

	i = 0;
	while (key[i].key_id != -1)
	{
		if (key[i].key_id == keycode)
			return (key[i].func);
		i++;
	}
	return (NULL);
}

int	keyboard(int key, t_engine *vars)
{
	t_key_func	key_f;

	key_f = get_key_func(key);
	if (key_f)
		key_f(vars);
	return (0);
}
