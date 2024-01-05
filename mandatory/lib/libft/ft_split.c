/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:13:17 by lrio              #+#    #+#             */
/*   Updated: 2023/11/10 18:25:11 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skip(size_t *a, const char *s, char c, int include)
{
	size_t	i;

	i = *a;
	if (include == 1)
		while (s[i] && s[i] == c)
			i++;
	else
		while (s[i] && s[i] != c)
			i++;
	*a = i;
}

static size_t	ft_count_word(char const *s, char sep)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	i = 0;
	j = 0;
	ft_skip(&i, s, sep, 1);
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == sep)
		{
			j = 0;
			while (s[i + j] == sep)
				j++;
			if (s[i + j])
				count ++;
		}
		i = i + j;
		j = 0;
		i++;
	}
	return (count + 1);
}

static void	*ft_free_split(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	count_word;

	i = 0;
	count_word = ft_count_word(s, c);
	tab = ft_calloc(count_word + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	start = 0;
	ft_skip(&start, s, c, 1);
	while (count_word-- != 0)
	{
		end = start;
		ft_skip(&end, s, c, 0);
		tab[i] = ft_substr(s, start, end - start);
		if (!tab[i])
			return (ft_free_split(tab));
		i++;
		start = end;
		ft_skip(&start, s, c, 1);
	}
	return (tab);
}
