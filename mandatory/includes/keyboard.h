/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:19:04 by lrio              #+#    #+#             */
/*   Updated: 2024/01/05 15:49:58 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H
# include "fractol.h"

typedef void	(*t_key_func)(t_vars *vars);

enum e_keyboard
{
	LEFT_CLICK = 1,
	A_DOWN = 65364,
	A_UP = 65362,
	A_RIGHT = 65363,
	A_LEFT = 65361,
	KEY_MINUS = 65451,
	KEY_PLUS = 65453,
	MOUSE_S_UP = 4,
	MOUSE_S_DOWN = 5,
	ESC = 65307,
	SPACE = 32,
	DEL = 65288,
	CR_1 = 91,
	CR_2 = 93,
	MINUS_DIGIT = 45,
	PLUS_DIGIT = 61,
	ONE = 49,
	TWO = 50,
	THREE = 51,
	FOUR = 52,
	NP_ONE = 65436,
	END = -1
};

typedef struct s_key
{
	enum e_keyboard	key_id;
	t_key_func		func;
}				t_key;

void	fone(t_vars *vars);
int		save(t_vars *vars);
void	keyfour(t_vars *vars);
void	keythree(t_vars *vars);
void	keytwo(t_vars *vars);
void	keyone(t_vars *vars);
int		keyboard(int key, t_vars *vars);
void	arrow_up(t_vars *vars);
void	arrow_down(t_vars *vars);
void	arrow_left(t_vars *vars);
void	arrow_right(t_vars *vars);
void	minus(t_vars *vars);
void	plus(t_vars *vars);
void	space(t_vars *vars);
void	addzi(t_vars *vars);
void	rmzi(t_vars *vars);
void	addzr(t_vars *vars);
void	rmzr(t_vars *vars);
#endif
