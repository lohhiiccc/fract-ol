/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:09:16 by lrio              #+#    #+#             */
/*   Updated: 2024/01/05 10:14:34 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_VAR_H
# define SET_VAR_H

# include "fractol.h"

void	set_vinfo_double(t_engine *vars, double num, int i);
void	set_vinfo_int(t_engine *vars, int num, int i);

#endif
