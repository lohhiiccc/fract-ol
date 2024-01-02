/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:19:04 by lrio              #+#    #+#             */
/*   Updated: 2024/01/02 17:07:50 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H
# include "fractol.h"

typedef void	(*t_key_func)(t_vars *vars);

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
# define NP_ONE 65436

void	save(t_vars *vars);
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
