/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvurur <yvurur@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:20:05 by yvurur            #+#    #+#             */
/*   Updated: 2022/07/11 12:26:29 by yvurur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(void *str)
{
	free(str);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*d;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	d = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!d || !s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		d[j++] = s1[i++];
	i = 0;
	while (s2[i])
		d[j++] = s2[i++];
	d[j] = '\0';
	free(s1);
	return (d);
}
