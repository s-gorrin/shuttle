#include "fdf.h"

static void	home(t_points *pix, t_grid *grid, int code)
{
	if (code == 'x') // sets points for a horizontal line
	{
		pix->x0 = grid->tlx + (WIDTH * 0.1); // was WIDTH
		pix->x1 = pix->x0 + grid->x_scale;
		pix->y1 = pix->y0;
	}
	if (code == 'y') // sets points for a vertical line
	{
		pix->y0 = grid->tly + (HEIGHT * 0.1);
		pix->y1 = pix->y0 + grid->y_scale;
		pix->x1 = pix->x0;
	}
}

static void	traverse(t_env *env, t_points *pix, t_grid *grid, int code)
{
	if (code == 'h') // horizontal line
	{
		line(env, pix);
		env->color = (env->color == GRN) ? LAV : GRN;
		pix->x0 = pix->x1;
		pix->x1 = pix->x1 + grid->x_scale; // was x_scale
	}
	if (code == 'v') // vertical line
	{
		line(env, pix);
		env->color = (env->color == GRN) ? LAV : GRN;
		pix->y0 = pix->y1;
		pix->y1 = pix->y1 + grid->y_scale;
	}
}

void		point_grid(t_env *env, t_grid *grid)
{
	// while not end points, draw line from start to start + scale
	t_points	pix;
	int			i;

	i = 0;
	pix.y0 = grid->tly + (HEIGHT * 0.1); // 50
	home(&pix, grid, 'x');
	while (i < grid->bry)//(pix.y0 <= (HEIGHT - (HEIGHT * 0.1)))
	{
		while (pix.x1 <= (HEIGHT - (HEIGHT * 0.1))) //(pix.x1 <= (WIDTH - (WIDTH * 0.1)))
			traverse(env, &pix, grid, 'h');
		pix.y0 += grid->y_scale;
		home(&pix, grid, 'x');
		i++;
	}
	pix.x0 = grid->tlx + (WIDTH * 0.1); // was WIDTH
	home(&pix, grid, 'y');
	while (pix.x0 <= (HEIGHT - (HEIGHT * 0.1))) // (pix.x0 <= (WIDTH - (WIDTH * 0.1)))
	{
		while (pix.y1 <= (HEIGHT - (HEIGHT * 0.1)))
			traverse(env, &pix, grid, 'v');
		pix.x0 += grid->x_scale; //was x_scale
		home(&pix, grid, 'y');
	}
}
// not sure why, but it's currently making an 11x10 grid.
// Something is fucky.