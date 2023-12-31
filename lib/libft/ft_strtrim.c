/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:11 by lrio              #+#    #+#             */
/*   Updated: 2023/11/10 16:35:14 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static char	*ft_strndup(const char *src, size_t n)
{
	char	*cpy;

	if (src[n] != '\0')
		n++;
	cpy = ft_calloc(n + 1, sizeof(char));
	if (!cpy)
		return (0);
	ft_strncpy(cpy, (char *)src, n);
	return ((char *)cpy);
}

static int	ft_is_in(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!set || ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	while (ft_is_in(set, s1[start]))
		start++;
	if (!s1[start])
		return (ft_strdup(""));
	while (ft_is_in(set, s1[end]))
		end--;
	new = ft_strndup(s1 + start, end - start);
	if (!new)
		return (NULL);
	return (new);
}
