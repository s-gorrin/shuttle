#inlcude "hnl.h"
/*
char	*buffer(int fd)
{
	int		ret;
	int		i;
	static int	iter;
	static char	buf[BUFSIZE + 1];
	static char	*line;

	i = 0;
	iter = 1;

	if ((ret = read(fd, buf, BUFSIZE)) < 0)
	{
		write(2, "Failed to read file.\n", 21);
		return (NULL);
	}
	str = (char *)malloc(sizeof(*str) * (BUFSIZE * iter);
	while (i < ret && buf[i] != '\n')
		i++;
	if (i == ret)			//  maybe helper function?
		memcpy(str, buf, ret);
	else
		write(1, buf, i);

}*/

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static int	i;
	int			j;
	char		buf[BUFF_SIZE + 1];

	j = i;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		while (buf[j] != '\n' && j != ret)
			j++;
		if (buf[j] == '\n')
		{
			memcpy(line, (buf + i), (j - i));
			i = j + 1;
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*next_line;
	char	*line;
	int		fd;

	if (ac != 2)
	{
		write(2, "usage: gnl source_file\n", 23);
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		write(2, "Failed to open file.\n", 21);
		return (NULL);
	}
	next_line = get_next_line((const int)fd, line);
	return (0);
}
