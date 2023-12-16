/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:29:33 by lrio              #+#    #+#             */
/*   Updated: 2023/12/16 06:54:47 by lrio             ###   ########.fr       */
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

# define DEL 65288

void	del(t_vars *vars)
{
	if (vars->info.settings.d_color == 1)
		vars->info.settings.d_color = 0;
	else
		vars->info.settings.d_color = 1;
	vars->info.needredraw = 1;
}

void	rmzr(t_vars *vars)
{
	vars->info.z.real -= 0.1;
	vars->info.needredraw = 1;
}
void	addzr(t_vars *vars)
{
	vars->info.z.real += 0.1;
	vars->info.needredraw = 1;
}

void	rmzi(t_vars *vars)
{
	vars->info.z.imag -= 0.1;
	vars->info.needredraw = 1;
}

void	addzi(t_vars *vars)
{
	vars->info.z.imag += 0.1;
	vars->info.needredraw = 1;
}

key_func	get_key_func(int keycode) {
	unsigned char i;
	const t_key key[] = {{A_UP, &arrow_up}, \
                        {A_LEFT, &arrow_left}, \
                        {A_RIGHT, &arrow_right}, \
                        {A_DOWN, &arrow_down}, \
                        {KEY_MINUS, &minus}, \
                        {KEY_PLUS, &plus}, \
                        {ESC, &esc}, \
                        {SPACE, &space}, \
						{DEL, &del}, \
						{93, &addzr}, \
						{91, &rmzr}, \
						{45, &addzi}, \
						{61, &rmzi}, \
                        {-1, NULL}};
	i = 0;
	while (key[i].key_id != -1)
	{
		if (key[i].key_id == keycode)
			return (key[i].func);
		i++;
	}
	return (NULL);
}

int	keyboard(int key, t_vars *vars)
{
	key_func	key_f;

	key_f = get_key_func(key);
	if (key_f)
		key_f(vars);
	printf("\n%d\n", key);
	return (0);
}
