/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:50:36 by lrio              #+#    #+#             */
/*   Updated: 2024/01/03 16:53:03 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putfloat_fd(double num, int fd)
{
	int	i;

	if (num < 0)
	{
		num = -num;
		if (-1 == ft_putchar_fd('-', fd))
			return (-1);
	}
	if (-1 == ft_putnbr_fd((int)num, fd) || -1 == ft_putchar_fd('.', fd))
		return (-1);
	i = 0;
	while (i < 15)
	{
		num -= (int)num;
		num *= 10;
		if (-1 == ft_putnbr_fd((int)num, fd))
			return (-1);
		i++;
	}
	return (0);
}
