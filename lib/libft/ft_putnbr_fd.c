/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:13:17 by lrio              #+#    #+#             */
/*   Updated: 2023/11/10 18:25:11 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long)n;
	if (num == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-num, fd);
		return ;
	}
	if (num < 10)
	{
		ft_putchar_fd(num + '0', fd);
		return ;
	}
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd('0' + (num % 10), fd);
	}
}
