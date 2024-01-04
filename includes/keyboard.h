/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:19:04 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 09:42:38 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H
# include "fractol.h"

typedef void	(*t_key_func)(t_engine *vars);

typedef struct s_key
{
	int			key_id;
	t_key_func	func;
}				t_key;

# define LEFT_CLICK 1
# define A_DOWN 65364
# define A_UP 65362
# define A_RIGHT 65363
# define A_LEFT 65361
# define KEY_MINUS 65451
# define KEY_PLUS 65453
# define MOUSE_S_UP 4
# define MOUSE_S_DOWN 5
# define ESC 65307
# define SPACE 32
# define DEL 65288
# define CR_1 91
# define CR_2 93
# define MINUS_DIGIT 45
# define PLUS_DIGIT 61
# define ONE 49
# define TWO 50
# define THREE 51
# define FOUR 52
# define NP_ONE 65436

void	save(t_engine *vars);
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
