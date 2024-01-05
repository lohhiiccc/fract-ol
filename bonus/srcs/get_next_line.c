/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <rio@student.42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:13:39 by lrio              #+#    #+#             */
/*   Updated: 2024/01/01 23:12:30 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>
#include "libft.h"

void	ft_setzero(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i)
		str[i++] = '\0';
}

char	*ft_fill(int fd, char buffer[BUFFER_SIZE + 1])
{
	int		i;
	char	*str;

	if (ft_strchr(buffer, '\n'))
		return (ft_strfjoin(ft_strdup(""), buffer));
	str = ft_strdup(buffer);
	if (!str)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || (i == 0 && buffer[0] == '\0'))
			return (free(str), ft_setzero(buffer, BUFFER_SIZE), NULL);
		if (i != 0)
		{
			buffer[i] = '\0';
			str = ft_strfjoin(str, buffer);
			if (!str)
				return (free(str), NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (str);
}

int	ft_next_buffer(char buffer[BUFFER_SIZE + 1])
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	tmp = ft_strdup(buffer + i);
	if (!tmp)
		return (-1);
	while (buffer[j])
		buffer[j++] = '\0';
	ft_memcpy(buffer, tmp, j - i);
	return (free(tmp), 1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	if (fd < 0 || fd > 1024)
		return (NULL);
	str = ft_fill(fd, buffer);
	if (!str)
		return (NULL);
	if (ft_next_buffer(buffer) == -1)
		return (free(str), NULL);
	return (str);
}
