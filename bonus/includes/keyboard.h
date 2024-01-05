/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:19:04 by lrio              #+#    #+#             */
/*   Updated: 2024/01/05 12:40:20 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H
# include "fractol.h"

typedef void	(*t_key_func)(t_engine *vars);

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

void	fone(t_engine *vars);
int		save(t_engine *vars);
void	keyfour(t_engine *vars);
void	keythree(t_engine *vars);
void	keytwo(t_engine *vars);
void	keyone(t_engine *vars);
int		keyboard(int key, t_engine *vars);
void	arrow_up(t_engine *vars);
void	arrow_down(t_engine *vars);
void	arrow_left(t_engine *vars);
void	arrow_right(t_engine *vars);
void	minus(t_engine *vars);
void	plus(t_engine *vars);
void	space(t_engine *vars);
void	addzi(t_engine *vars);
void	rmzi(t_engine *vars);
void	addzr(t_engine *vars);
void	rmzr(t_engine *vars);
#endif
