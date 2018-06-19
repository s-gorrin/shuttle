#include "fdf.h"
#include <stdio.h>

int	handle_mouse(int button, int x, int y, void *param)
{
	int count;

	count = 0;
	if (!button || param)
		write(1, " ", 1);
	if (button == 0)
		return (0);
	else if (button == 2)
		write(1, "rclick\n", 7);
	/*else
	{
		count++;
		if (x < 100 && y < 100)
			write(1, "top left\n", 9);
		else if (x > 100 && x < 400 && y > 100 && y < 400)
			write(1, "middle\n", 7);
		else
			ft_putchar('x');
	}*/
	else
	{
		ft_putstr(" click: x = ");
		ft_putnbr(x);
		ft_putstr(" y = ");
		ft_putnbr(y);
	}
	return (count);
}

static t_env	set_env(void)
{
	t_env	env;

	//env = malloc(sizeof(t_env));
	env.bpp = 32;
	env.size_line = WIDTH;
	env.endian = 1;
	env.mlx_ptr = mlx_init();
	env.window = mlx_new_window(env.mlx_ptr, WIDTH, HEIGHT, "window");
	env.image = mlx_new_image(env.mlx_ptr, WIDTH, HEIGHT);
	env.img_data = (int *)mlx_get_data_addr(env.image, &env.bpp,
		&env.size_line, &env.endian);
	return (env);
}

int	fdf_error(void)
{
	ft_putstr("Could not proceed.\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_env	env;
	int		fd;

	if (ac < 2)
	{
		write(1, "Too few arguments.\n", 19);
		return (0);
	}
	env = set_env(); //populate enviroment struct

	//todo: read file, get number of points on first line -done
	//		get number of lines (y), add values to t_env
	//		draw grid based on file data

	if (!(fd = open(av[1], O_RDONLY)))
	{
		ft_putstr("failed to open\n");
		return (0);
	}
	read_input(av[1]); //reading map happens here. Returns **map
//	draw(&env, 0, 0);
//	mlx_string_put(env.mlx_ptr, env.window, 100, 100, 0x9eb3d6, "string");
	// Mouse and Key hooks:
	mlx_mouse_hook(env.window, handle_mouse, (void *)0);
	mlx_key_hook(env.window, handle_key, &env);

	// Putting image to env.window:

//	mlx_new_image(env.mlx_ptr, height, width);
//	env.image = mlx_xpm_file_to_image(env.mlx_ptr, av[2], &height, &width);
	//mlx_put_image_to_window(env.mlx_ptr, env.window, env.image, 0, 0);
//	draw(&env, deez_x, deez_y);

	// Line

	mlx_loop(env.mlx_ptr);
	return (0);
}
//todo: learn about functions as parameters.
//todo: learn where "key" comes from.
//todo: learn how to draw. Do I need to write drawing functions?
// going to need structs to store coordinates, etc
// use macros for color pallet

//todo: free function (see mallocs in "read_input")
