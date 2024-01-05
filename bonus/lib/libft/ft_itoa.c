/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:13:17 by lrio              #+#    #+#             */
/*   Updated: 2024/01/04 09:46:58 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev_tab(char *tab, size_t size)
{
	char		tmp_tab;
	size_t		i;

	i = 0;
	while (i < size / 2)
	{
		tmp_tab = tab[size - i - 1];
		tab[size - i - 1] = tab[i];
		tab[i] = tmp_tab;
		i++;
	}
}

static int	ft_get_len(long long n)
{
	size_t	count;

	if (n < 0)
		n = -n;
	count = 0;
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	ft_make_str(char *str, long long num)
{
	size_t	j;
	int		is_negative;

	is_negative = 0;
	j = 0;
	if (num < 0)
	{
		is_negative = 1;
		j++;
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[j] = (num % 10) + '0';
		num = num / 10;
		j++;
	}
	if (is_negative)
		ft_rev_tab(str + 1, ft_strlen(str) - 1);
	else
		ft_rev_tab(str, ft_strlen(str));
}

char	*ft_itoa(long n)
{
	long long	num;
	char		*str;
	size_t		i;

	num = (long long)n;
	i = ft_get_len(num);
	if (num <= 0)
		i++;
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	ft_make_str(str, num);
	return (str);
}
