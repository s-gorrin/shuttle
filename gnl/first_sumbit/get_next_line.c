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
		{
//			temp = *line;
//			*line = ft_strnjoin((const char*)*line, (const char*)*storage, i);
//			ft_strdel(&temp);
//			i++;
//			temp = *storage;
//			*storage = ft_strnew(ft_strlen(*storage + i));
//			ft_strlcpy(*storage, temp + i, ft_strlen(temp + i) + 1);
//			ft_strdel(&temp);
//
//			len = ft_strlen(*storage + i);
//			ft_memmove(*storage, *storage + i, len);
//			(*storage)[len] = '\0';
			return (crane(storage, line, i, &temp));
		}
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
	static char	*storage[256];

	if (!line || fd < 0)
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
/*
int	main(int ac, char **av)
{
	char	*line;
	int		fd1;
//	int		fd2;
//	int		fd3;

	if (ac < 2)
	{
		write(2, "usage: gnl source_file\n", 23);
		return (0);
	}
	if ((fd1 = open(av[1], O_RDONLY)) < 0)
	{
		write(2, "Failed to open file.\n", 21);
		return (0);
	}
	if ((fd2 = open(av[2], O_RDONLY)) < 0)
	{
		write(2, "Failed to open file.\n", 21);
		return (0);
	}
	if ((fd3 = open(av[3], O_RDONLY)) < 0)
	{
		write(2, "Failed to open file.\n", 21);
		return (0);
	}
	while (get_next_line((const int)fd1, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
//	get_next_line((const int)fd2, &line);
//	write(1, line, ft_strlen(line));
//	write(1, "\n", 1);
//	get_next_line((const int)fd3, &line);
//	write(1, line, ft_strlen(line));
//	write(1, "\n", 1);
//	get_next_line((const int)fd1, &line);
//	write(1, line, ft_strlen(line));
//	write(1, "\n", 1);
//	get_next_line((const int)fd2, &line);
//	write(1, line, ft_strlen(line));
//	write(1, "\n", 1);
//	get_next_line((const int)fd3, &line);
//	write(1, line, ft_strlen(line));
//	write(1, "\n", 1);

	close(fd1);
//	close(fd2);
//	close(fd3);
	ft_strdel(&line);
	return (0);
}
*/
