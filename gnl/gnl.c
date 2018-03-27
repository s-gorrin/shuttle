#inlcude "hnl.h"

char	*buffer(char *input)
{
	int		fd;
	int		ret;
	int		i;
	static int	iter;
	static char	buf[BUFSIZE + 1];
	static char	*line;

	i = 0;
	iter = 1;
	if ((fd = open(input, O_RDONLY)) < 0)
	{
		write(2, "Failed to open file.", 20);
		return (NULL);
	}
	if ((ret = read(fd, buf, BUFSIZE)) < 0)
	{
		write(2, "Failed to read file.", 20);
		return (NULL);
	}
	str = (char *)malloc(sizeof(*str) * (BUFSIZE * iter);
	while (i < ret && buf[i] != '\n')
		i++;
	if (i == ret)			// MAGIC HAPPENS HERE. maybe helper function?
		memcpy(str, buf, ret);
	else
		write(1, buf, i);

}

int	main(int ac, char **av)
{
	char	*str;

	if (ac != 2)
	{
		write(2, "usage: gnl source_file", 22);
		return (0);
	}
	str = buffer(av[1]);
	return (0);
}
