/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:37:52 by lrio              #+#    #+#             */
/*   Updated: 2023/11/10 16:37:54 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\f' || str[i] == ' ' \
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
			i++;
		else
			return (i);
	}
	return (i);
}

static long	ft_atol(const char *str)
{
	int		start;
	long	i;
	long	return_value;
	int		is_neg;

	is_neg = 0;
	i = 0;
	return_value = 0;
	start = ft_isspace(str);
	if (str[start] == '+' || str[start] == '-')
		if (str[start++] == '-')
			is_neg = 1;
	while (str[start + i] && ft_isdigit(str[start + i]))
		return_value = (return_value * 10) + (str[start + i++] - '0');
	if (return_value < 0)
	{
		if (is_neg == 1)
			return (LONG_MAX);
		return (LONG_MIN);
	}
	if (is_neg == 1)
		return_value = -return_value;
	return (return_value);
}

int	ft_atoi(const char *str)
{
	return (ft_atol(str));
}
