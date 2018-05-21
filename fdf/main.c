#include "minilibx_macos_10.11/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	deal_mouse(int button, int x, int y, void *param)
{
	int count;

	count = 0;
	if (!button || param)
		write(1, " ", 1);
	if (button == 0)
		return (0);
	else if (button == 2)
		write(1, "rclick\n", 7);
	else
	{
		count++;
		if (x < 100 && y < 100)
			write(1, "top left\n", 9);
		else if (x > 100 && x < 400 && y > 100 && y < 400)
			write(1, "middle\n", 7);
		else
			ft_putchar('x');
	}
	return (count);
}

int	deal_key(int key, void *param)
{
	if (param)
		return (0);
	if (key)
	{
		ft_putstr(ft_itoa_base(key, 16));
		ft_putchar(' ');
	}
	return (0);
}

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*window;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		fd;
	int		color;

	color = 0xFFFFFF;
	if (ac < 2)
	{
		write(1, "Too few arguments.\n", 19);
		return (0);
	}
	fd = open(av[2], O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (0);
	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 500, 500, av[1]);
	mlx_pixel_put(mlx_ptr, window, atoi(buf), atoi(buf), 0xeeeeee);
	mlx_pixel_put(mlx_ptr, window, 100, 100, 0xffffff);
	mlx_pixel_put(mlx_ptr, window, 100, 400, 0xffffff);
	mlx_pixel_put(mlx_ptr, window, 400, 100, 0xffffff);
	mlx_pixel_put(mlx_ptr, window, 400, 400, 0xffffff);
	mlx_mouse_hook(window, deal_mouse, (void *)0);
	mlx_key_hook(window, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
//todo: learn about functions as parameters.
//todo: learn where "key" comes from.
//todo: 
