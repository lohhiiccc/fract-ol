/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:37:18 by lrio              #+#    #+#             */
/*   Updated: 2023/11/10 16:37:19 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	cc = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return (((char *)s) + i);
		i++;
	}
	if (s[i] == cc)
		return ((char *)s + i);
	return (NULL);
}
