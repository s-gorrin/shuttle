#include "fdf.h"
#include <stdio.h>

/*static void			initialize(int *i, int *x, int *y)
{
	*i = 0;
	*x = 0;
	*y = 0;
}*/

static void			pre_error(int code)
{
	if (code == 1)
		ft_putstr_fd("Could not open file.\n", 2);
	if (code == 2)
		ft_putstr_fd("Invalid file.\n", 2);
	if (code == 3)
		ft_putstr_fd("Bad map malloc.\n", 2);
	if (code == 4)
		ft_putstr_fd("Bad line malloc.\n", 2);
	exit (0);
}

static t_check_in	prechecker(char *filename)
{
	t_check_in	data;
	char		*line;

	data.fd = 0;
	if (!(data.fd = open(filename, O_RDONLY)))
		pre_error(1);
	data.x = 0;
	data.y = 0;
	while (get_next_line(data.fd, &line))
	{
		if (data.x == 0)
			data.x = wc(line, ' ');
		if (wc(line, ' ') != data.x)
			pre_error(2);
		data.y++;
	}
	close (data.fd);
	if (!(data.fd = open(filename, O_RDONLY)))
		pre_error(1);
	data.mx = 0;
	data.my = 0;
	printf("x = %d, y = %d\n", data.x, data.y); // PRINTF
	return (data);
}

t_node				*read_input(char *filename)
{
	t_node		*map; // The Map, as a struct of floats.
	t_node		*save; // BRUK?
	t_check_in	data;
	char		*line; // line of the read in

	data = prechecker(filename);
	if (!(map = malloc(sizeof(t_node) * (data.y * data.x))))
		pre_error(3);
	printf("malloc'd the good size: %d\n", data.x * data.y); // PRINTF
	save = map; // BRUK?
	// initialize(&i, &x, &y);
	while (get_next_line(data.fd, &line) != 0)
	{
		while (*line != '\0')
		{
			while (ft_isspace(*line))
				line++;
			map->x = data.mx;
			map->y = data.my;
			map->z = ft_atoi(line);
			map->total_x = data.x;
			map->total_y = data.y;
			while (!ft_isspace(*line) && *line != '\0')
				line++;
			data.mx++;
			map++;
		}
		data.mx = 0;
		data.my++;
	}
	close (data.fd);
	return (save); // should be map?
}
