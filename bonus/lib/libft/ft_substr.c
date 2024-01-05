/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:26 by lrio              #+#    #+#             */
/*   Updated: 2023/11/10 16:35:29 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	f_get_len(const char *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	while (s[i + (size_t)start] && i < len)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	new_len;

	if (ft_strlen(s) < start)
	{
		new = ft_calloc(1, sizeof(char));
		return (new);
	}
	new_len = f_get_len(s, start, len);
	new = ft_calloc(new_len + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, (char *)s + start, new_len);
	return (new);
}
