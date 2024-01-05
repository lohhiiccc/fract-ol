/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <rio@student.42lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:23:28 by lrio              #+#    #+#             */
/*   Updated: 2024/01/01 23:14:00 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*get_next_line(int fd);
char	*ft_strfjoin(char *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strclen(const char *str, int c);
void	ft_setzero(char *str, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
