/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:22:24 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/26 17:20:28 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static	char	*ft_joinbuff(char **line, char **buff)
{
	int		size;
	char	*ret;

	size = ft_strlen(*buff);
	if (*line)
		size += ft_strlen(*line);
	ret = (char *)malloc (size + 1);
	if (*line)
	{
		ft_strncpy(ret, *line, ft_strlen(*line), '\n');
		free(*line);
	}
	ft_strncat(ret, *buff, size + 1);
	return (ret);
}

static	char	*ft_after(char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s[i] != '\n')
		i++;
	i++;
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	tmp = ft_strncpy(tmp, &s[i], BUFFER_SIZE, '\0');
	if (s)
		free(s);
	return (tmp);
}

static	int	ft_full(char **line, char **buff)
{
	if (*line)
		resetbuff(*line);
	if (!*buff)
		*buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!ft_iselig(*buff))
	{
		*buff = ft_after(*buff);
		if (!*buff)
			return (-1);
		if (**buff != '\0')
			*line = ft_joinbuff(line, buff);
		if (!ft_iselig(*buff))
			return (1);
	}
	return (0);
}

int	ft_free(char **buff)
{
	if (*buff)
	{
		free(*buff);
		*buff = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff[1025];
	int			n;

	*line = (char *)malloc(1);
	if (fd < 0 || !line)
		return (-1);
	n = ft_full(line, &buff[fd]);
	if (n != 0)
		return (n);
	n = 1;
	while (ft_iselig(buff[fd]) && n > 0)
	{
		resetbuff(buff[fd]);
		n = read(fd, buff[fd], BUFFER_SIZE);
		buff[fd][n] = '\0';
		if (n > 0)
			*line = ft_joinbuff(line, &buff[fd]);
		if (n == 0)
			return (ft_free(&buff[fd]));
	}
	if (n > 0)
		return (1);
	return (n);
}
