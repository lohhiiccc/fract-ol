/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:38:22 by lrio              #+#    #+#             */
/*   Updated: 2023/11/10 16:38:24 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	if (n != 0)
	{
		while (n != 0)
		{
			if (*(const unsigned char *)p1++ != *(const unsigned char *)p2++)
				return (*(const unsigned char *)--p1 \
				- *(const unsigned char *)--p2);
			n--;
		}
	}
	return (0);
}
