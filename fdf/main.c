#include "fdf.h"

void	draw(t_env *env, int x, int y)
{
	ft_bzero(env->img_data, (HEIGHT * WIDTH * sizeof(int)));
	// make new image
	mlx_clear_window(env->mlx_ptr, env->window);
	mlx_put_image_to_window(env->mlx_ptr, env->window, env->image, x, y);
}

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

int handle_key(int key, t_env *env)
{
	t_points pix;

	pix.x0 = 100;
	pix.y0 = 400;
	pix.x1 = 400;
	pix.y1 = 400;
	if (key == 0x35)
		exit(0);
	if (key == 0x1)
		line(env, &pix);
	return (key);
}

int	main(int ac, char **av)
{
	t_env		env;
	t_points	input;
	int			height;
	int			width;

	height = 64;
	width = 64;
	env.bpp = 32;
	env.size_line = WIDTH;
	env.endian = 1;
	if (ac < 2)
	{
		write(1, "Too few arguments.\n", 19);
		return (0);
	}
	env.mlx_ptr = mlx_init();
	env.window = mlx_new_window(env.mlx_ptr, WIDTH, HEIGHT, av[1]);
	env.image = mlx_new_image(env.mlx_ptr, WIDTH, HEIGHT);
	env.img_data = (int *)mlx_get_data_addr(env.image, &env.bpp, &env.size_line, &env.endian);

	input.x0 = ft_atoi(av[2]);
	input.x1 = ft_atoi(av[3]);
	input.y0 = ft_atoi(av[4]);
	input.y1 = ft_atoi(av[5]);
	line(&env, &input);
//	mlx_string_put(env.mlx_ptr, env.window, 100, 100, 0x9eb3d6, "string");
	// Mouse and Key hooks:
	mlx_mouse_hook(env.window, handle_mouse, (void *)0);
	mlx_key_hook(env.window, handle_key, &env);

	// Debugging.
	ft_putstr("got to the 1st place\n");

	// Putting image to env.window:

//	mlx_new_image(env.mlx_ptr, height, width);
//	env.image = mlx_xpm_file_to_image(env.mlx_ptr, av[2], &height, &width);
	//mlx_put_image_to_window(env.mlx_ptr, env.window, env.image, 0, 0);
//	draw(&env, deez_x, deez_y);

	// Line

	ft_putstr("got to the 2nd place\n");
	ft_putstr("got to the 4th place\n");
	mlx_loop(env.mlx_ptr);
	return (0);
}
//todo: learn about functions as parameters.
//todo: learn where "key" comes from.
//todo: learn how to draw. Do I need to write drawing functions?
// going to need structs to store coordinates, etc
// use macros for color pallet
