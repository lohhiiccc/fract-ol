/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:43:42 by lrio              #+#    #+#             */
/*   Updated: 2023/12/31 17:57:15 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORSET_H
#define COLORSET_H

typedef int (*colorset)(t_pixel pixel);

int colorset_two(t_pixel pixel);
int	colorset_one(t_pixel pixel);
int colorset_three(t_pixel pixel);
#endif
