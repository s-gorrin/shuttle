/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:18:07 by sgorrin           #+#    #+#             */
/*   Updated: 2018/05/07 16:59:10 by snake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	crane(char **storage, char **line, size_t i, char **temp)
{
	*temp = *line;
	*line = ft_strnjoin((const char*)*line, (const char*)*storage, i);
	if ((*temp)[0])
		ft_strdel(temp);
	i++;
	*temp = *storage;
	*storage = ft_strnew(ft_strlen(*storage + i));
	ft_strlcpy(*storage, *temp + i, ft_strlen(*temp + i) + 1);
	ft_strdel(temp);
	return (1);
}

static int	shipping(char **storage, char **line, int ret)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (line[0] == '\0')
		*line = "";
	while ((*storage)[i] != '\0')
	{
		if ((*storage)[i] == '\n' || ret == 0)
			return (crane(storage, line, i, &temp));
		i++;
	}
	temp = *line;
	*line = ft_strnjoin((const char*)*line, (const char*)*storage, i);
	if (temp[0])
		ft_strdel(&temp);
	ft_strdel(storage);
	return (0);
}

static int	dumb(char **storage)
{
	if (!(*storage)[0])
		ft_strdel(storage);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*storage[MAX_FD];

	if (!line || fd < 0 || fd >= MAX_FD)
		return (-1);
	*line = NULL;
	if (storage[fd] && storage[fd][0] != '\0')
		if ((shipping(&storage[fd], line, 1)) == 1)
			return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		storage[fd] = ft_strnew(ret);
		ft_memcpy(storage[fd], buf, ret);
		if ((shipping(&storage[fd], line, ret)) == 1)
			return (dumb(&storage[fd]));
	}
	ft_strdel(&storage[fd]);
	if (!(*line))
		return (0);
	return (1);
}
