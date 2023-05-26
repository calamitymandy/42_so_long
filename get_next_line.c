/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:25:50 by amdemuyn          #+#    #+#             */
/*   Updated: 2022/12/15 16:07:15 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buf;
	int		bytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[bytes] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_next_line(str);
	return (line);
}
