#include "minilibx_macos_10.11/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define GREEN 0x2eb82e

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*window;
	void		*image;
	int			*img_data;
}				t_env;

typedef struct	s_points
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_points;

int deez_x;
int deez_y;

void	draw(t_env *env, int x, int y)
{
	mlx_clear_window(env->mlx_ptr, env->window);
	mlx_put_image_to_window(env->mlx_ptr, env->window, env->image, x, y);
}


//todo: handle horizontal lines
//todo: handle vertical lines
//todo: create line struct to hold all the variables
void	line(t_env *env, t_points *pix)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy; 
	int	err;
	int	e2;

	dx = ft_abs(pix->x1 - pix->x0);
	sx = pix->x0 < pix->x1 ? 1 : -1;
	dy = ft_abs(pix->y1 - pix->y0);
	sy = pix->y0 < pix->y1 ? 1 : -1; 
	err = (dx > dy ? dx : -dy ) / 2;
	while (pix->x0 != pix->x1 && pix->y0 != pix->y1)
	{
		mlx_pixel_put(env->mlx_ptr, env->window, pix->x0, pix->y0, GREEN);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			pix->x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			pix->y0 += sy;
		}
	}
}
/*
void drawline(t_env *env, t_points *points)
{
	int dx, dy, p, x, y;
 
	dx=points->x1-points->x0;
	dy=points->y1-points->y0;
 
	x=points->x0;
	y=points->y0;
 
	p=2*dy-dx;
 
	while(x<points->x1)
	{
		if(p>=0)
		{
			mlx_pixel_put(env->mlx_ptr, env->window, x, y, GREEN);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			mlx_pixel_put(env->mlx_ptr, env->window, x, y, GREEN);
			p=p+2*dy;
		}
		x=x+1;
	}
}
*/
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
/*	if (key)
	{
		ft_putstr(ft_itoa_base(key, 16));
		ft_putchar(' ');
	}*/

	pix.x0 = 300;
	pix.y0 = 400;
	pix.x1 = 400;
	pix.y1 = 50;
	if (key == 0x7c)
		deez_x += 10;
	if (key == 0x7b)
		deez_x -= 10;
	if (key == 0x7d)
		deez_y += 10;
	if (key == 0x7e)
		deez_y -= 10;
	if (key == 0x35)
		exit(0);
//	draw(env, deez_x, deez_y);

	if (key == 0x1)
		line(env, &pix);
	return (key);
}

int	main(int ac, char **av)
{
	t_env	env;
	int		height;
	int		width;

	height = 64;
	width = 64;

	deez_x = 0;
	deez_y = 0;

	if (ac < 2)
	{
		write(1, "Too few arguments.\n", 19);
		return (0);
	}
	env.mlx_ptr = mlx_init();
	env.window = mlx_new_window(env.mlx_ptr, 500, 500, av[1]);

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
