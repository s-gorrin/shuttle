#include "minilibx_macos_10.11/mlx.h"

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*window;

	if (ac > 2)
		return (0);
	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 500, 500, av[1]);
	mlx_loop(window);
	return (0);
}
