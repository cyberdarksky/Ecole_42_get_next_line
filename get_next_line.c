/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvurur <yvurur@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:34:40 by yvurur            #+#    #+#             */
/*   Updated: 2022/07/11 12:23:35 by yvurur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_str(char *str, int *tmp)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	if (!str[i])
		return (ft_free(str));
	len = ft_strlen(&str[*tmp]);
	dest = (char *)malloc(len + 1);
	while (str[*tmp + i])
	{
		dest[i] = str[*tmp + i];
		i++;
	}
	dest[i] = '\0';
	free(str);
	return (dest);
}

char	*load_to_next(char *str, int *tmp)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = -1;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	dest = (char *)malloc(i + 1);
	while (++j < i)
		dest[j] = str[j];
	dest[j] = '\0';
	*tmp = i;
	return (dest);
}

char	*load_str(int fd, char *str)
{
	char	*buff;
	int		rc;

	rc = 1;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!(ft_strchr(str, '\n')) && rc)
	{
		rc = read(fd, buff, BUFFER_SIZE);
		if (rc == -1)
			return (ft_free(buff));
		buff[rc] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = load_str(fd, str);
	if (!str)
		return (NULL);
	line = load_to_next(str, &tmp);
	str = update_str(str, &tmp);
	return (line);
}
/*
int	main(void)
{
	int fd;
	fd = open("dosya.txt", O_RDONLY, 0644);

	// fd = open("dosya.txt", O_CREAT | O_RDWR, 0644);
	// write(fd, "yakup\nvurur\nson", 16);
	// close(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
*/
