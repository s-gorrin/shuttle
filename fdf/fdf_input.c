#include "fdf.h"

int	in_error(void)
{
	//modify for different error codes
	ft_putstr("There was a problem.\n");
	return (0);
}

int	check_x(int *x, char *line)
{
	// all the x stuff goes here.

}

int	read_in(t_env *env, int fd)
{
	t_node	*xyz;
	char	*line;
	int		i; // place in the input line
	int		j; // struct incriment
	int		x; // total number of points per line
	int		y; // total number of lines
	int		xi; // x incriment. which point in the line

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	xi = 0;
	xyz = NULL;
	while (get_next_line(fd, &line))
	{
		x = (x == 0) ? wc(line, ' ') : x;
		if (wc(line, ' ') != x)
			return (in_error());
		while (line[i])
		{
			if (ft_isdigit(line[i]))
			{
				xyz[j].y = y;
				xyz[j].x = xi;
				xyz[j].z = ft_atoi(line + i);
				while (ft_isdigit(line[i]))
					i++;
				xi++;
			}
			//turning map numbers into xyz values goes here.
			//into t_node xyz
			i++;
		}
		ft_strdel(&line);
		y++;
	}
	return (1); //successfuly read file and created xyz
}
