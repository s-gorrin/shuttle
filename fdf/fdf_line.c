#include "fdf.h"

static void	ortho_line(t_env *env, t_points *pix)
{
	int	inc;

	inc = 1;
	if (pix->x0 == pix->x1)
	{
		inc = (pix->y0 < pix->y1) ? 1 : -1;
		while (pix->y0 != pix->y1)
		{
//			mlx_pixel_put(env->mlx_ptr, env->window, pix->x0, pix->y0, GREEN);
			env->img_data[pix->x0 + (pix->y0 * WIDTH)] = GREEN;
			pix->y0 += inc;
		}
	}
	if (pix->y0 == pix->y1)
	{
		inc = (pix->x0 < pix->x1) ? 1 : -1;
		while (pix->x0 != pix->x1)
		{
//			mlx_pixel_put(env->mlx_ptr, env->window, pix->x0, pix->y0, GREEN);
			env->img_data[pix->x0 + (pix->y0 * WIDTH)] = GREEN;
			pix->x0 += inc;
		}
	}
}

void	   line(t_env *env, t_points *pix)
{
	t_line	line;

	if (pix->x0 == pix->x1 || pix->y0 == pix->y1)
		ortho_line(env, pix);
	line.dx = ft_abs(pix->x1 - pix->x0);
	line.sx = pix->x0 < pix->x1 ? 1 : -1;
	line.dy = ft_abs(pix->y1 - pix->y0);
	line.sy = pix->y0 < pix->y1 ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy ) / 2;
	while (pix->x0 != pix->x1 && pix->y0 != pix->y1)
	{
//		mlx_pixel_put(env->mlx_ptr, env->window, pix->x0, pix->y0, GREEN);
		env->img_data[pix->x0 + (pix->y0 * WIDTH)] = GREEN;
		line.e2 = line.err;
		if (line.e2 > -line.dx)
		{
			line.err -= line.dy;
			pix->x0 += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			pix->y0 += line.sy;
		}
	}
}
