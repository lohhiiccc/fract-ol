/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:37:43 by lrio              #+#    #+#             */
/*   Updated: 2023/11/10 16:37:44 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	while (size != 0)
	{
		if (s[size] == (char)c)
			return ((char *)s + size);
		size--;
	}
	if (s[size] == (char)c)
		return ((char *)s + size);
	return (NULL);
}
