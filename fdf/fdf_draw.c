#include "fdf.h"

void	draw(t_env *env, int x, int y)
{
	// make new image
	mlx_clear_window(env->mlx_ptr, env->window);
	mlx_put_image_to_window(env->mlx_ptr, env->window, env->image, x, y);
	ft_bzero(env->img_data, (HEIGHT * WIDTH * sizeof(int)));
}
