#include "fdf.h"
#include "stdio.h"

int	fdf_grid(t_env *env, t_grid *grid)
{
	t_points	pix;

	//env->img_data = NULL;
	pix.x0 = grid->tlx; //100
	pix.y0 = grid->tly; //100
	pix.x1 = grid->brx; //400
	pix.y1 = grid->tly; //100
	while (pix.y1 <= grid->bry)
	{
		line(env, &pix);
		pix.x0 = grid->tlx;
		pix.y0 += grid->scale;
		pix.y1 += grid->scale;
		printf("y0 = %d, y1 = %d, looped\n", pix.y0, pix.y1);
	}
	pix.y0 = grid->tly;
	pix.x1 = grid->tlx;
	pix.y1 = grid->bry;
	while (pix.x1 <= grid->brx)
	{
		line(env, &pix);
		pix.y0 = grid->tly;
		pix.x0 += grid->scale;
		pix.x1 += grid->scale;
	}
	return (1);
}

int	handle_key(int key, t_env *env)
{
	t_points	pix;
	t_grid		grid;
	static int	y;

	pix.x0 = 0;
	pix.y0 = 100;
	pix.x1 = 500;
	pix.y1 = 100;
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
	if (key == 0x31)
	{
		grid.tlx = 100;
		grid.tly = 100;
		grid.brx = 401;
		grid.bry = 401;
		grid.scale = 50;
		if (fdf_grid(env, &grid))
			draw(env, 0, 0);
	}
	return (key);
}
