/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:36:17 by lrio              #+#    #+#             */
/*   Updated: 2023/11/10 16:36:19 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (ft_strlen(dst) > n)
		destlen = n;
	else
		destlen = ft_strlen(dst);
	while (src[i] != '\0' && destlen + i + 1 < n)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	if (destlen < n)
		dst[destlen + i] = '\0';
	return (destlen + srclen);
}
