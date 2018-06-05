#include "fdf.h"

void	fdf_grid(t_env *env, t_grid *grid)
{

}

// Grid concept is flawed. Do better.

int handle_key(int key, t_env *env)
{
	t_points	pix;
	t_grid		grid;
	static int	y;

	pix.x0 = 0;
	pix.y0 = 0;
	pix.x1 = 500;
	pix.y1 = 0;
	if (key == 0x35)
		exit(0);
	if (key == 0x1)
	{
		line(env, &pix);
		draw(env, 0, y += 5);
	}
	if (key == 0xD)
	{
		line(env, &pix);
		draw(env, 0, y -= 5);
	}
	if (key == 0x24)
	{
		grid.tlx = 100;
		grid.tly = 100;
		grid.brx = 400;
		grid.bry = 400;
		grid.scale = 50;
		grid.rot = 0;
		fdf_grid(env, &grid);
		draw(env, 0, 0);
	}
	return (key);
}
