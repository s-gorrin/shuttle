#include "../get_next_line.h"
#include <stdio.h>

static int	usage(void)
{
	ft_putendl("usage: get_next_line file1 file2 file3");
	return (0);
}

int	main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	int		fd3;
//	int		fd4;
//	int		fd5;
//	int		fd6;
	char	*line1;
	char	*line2;
	char	*line3;

	fd1 = 0;
	fd2 = 0;
	fd3 = 0;
	if (ac < 2)
		return (usage());
//	fd4 = open(av[4], O_RDONLY);
//	fd5 = open(av[5], O_RDONLY);
//	fd6 = open(av[6], O_RDONLY);
	if ((fd1 = open(av[1], O_RDONLY)) < 0)
	{
		write(2, "Failed to open file.\n", 21);
		return (0);
	}
	if (ac >= 3)
		if ((fd2 = open(av[2], O_RDONLY)) < 0)
		{
			write(2, "Failed to open file.\n", 21);
			return (0);
		}
	if (ac >= 4)
		if ((fd3 = open(av[3], O_RDONLY)) < 0)
		{
			write(2, "Failed to open file.\n", 21);
			return (0);
		}
//	get_next_line((const int)fd1, &line1);
//	ft_putendl(line1);
//	ft_strdel(&line1);
//	printf("%d\n%d\n%d\n%d\n%d\n%d\n", fd1, fd2, fd3, fd4, fd5, fd6);
	printf("%d\n%d\n%d\n", fd1, fd2, fd3);
	while (get_next_line((const int)fd1, &line1) > 0)
	{
		ft_putendl(line1);
		if (fd2)
		{
			get_next_line((const int)fd2, &line2);
			ft_putendl(line2);
			ft_strdel(&line3);
		}
		if (fd3)
		{
			get_next_line((const int)fd3, &line3);
			ft_putendl(line3);
			ft_strdel(&line3);
		}
		ft_strdel(&line1);
	}
	close(fd1);
	if (fd2)
		close(fd2);
	if (fd3)
		close(fd3);
//	close(fd4);
//	close(fd5);
//	close(fd6);
	return (0);
}
