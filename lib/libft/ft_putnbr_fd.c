/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:13:17 by lrio              #+#    #+#             */
/*   Updated: 2024/01/03 16:25:45 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long n, int fd)
{
	long long	num;

	num = (long long)n;
	if (num < 0)
	{
		if (-1 == ft_putchar_fd('-', fd))
			return (-1);
		num = -num;
	}
	if (num < 10)
	{
		if (-1 == ft_putchar_fd(num + '0', fd))
			return (-1);
		return (1);
	}
	else
	{
		if (-1 == ft_putnbr_fd(num / 10, fd))
			return (-1);
		if (-1 == ft_putchar_fd('0' + (num % 10), fd))
			return (-1);
	}
	return (1);
}
