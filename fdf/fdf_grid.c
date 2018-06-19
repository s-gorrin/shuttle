#include "fdf.h"

void	point_grid(t_env *env, t_grid *grid)
{
	// while not end points, draw line from start to start + scale
	// I was gonna write more instructions, but I think that's it.
	t_points	pix;

	pix.x0 = grid->tlx + (WIDTH * 0.1); // 50
	pix.y0 = grid->tly + (HEIGHT * 0.1); // 50
	pix.x1 = pix.x0 + grid->x_scale; // 130
	pix.y1 = pix.y0; // 50
	while (pix.x1 <= WIDTH - (WIDTH * 0.1))
	{
		line(env, &pix);
		env->color = (env->color == GRN) ? LAV : GRN;
		pix.y0 = grid->tly + (HEIGHT * 0.1);
		pix.x0 = pix.x1;
		pix.x1 = pix.x1 + grid->x_scale;
	}
}
