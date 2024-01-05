/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:50 by lrio              #+#    #+#             */
/*   Updated: 2023/11/10 16:35:54 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t			width;
	char			*cpy;

	width = ft_strlen(src) + 1;
	cpy = malloc(((int)width));
	if (!cpy)
		return (0);
	ft_strlcpy(cpy, (char *)src, width);
	return ((char *)cpy);
}
