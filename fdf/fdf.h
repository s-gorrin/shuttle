#ifndef FDF_H
# define FDF_H
# include "minilibx_macos_10.11/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define GREEN 0x2eb82e
# define LAV 0xaa99ee
# define WIDTH 500
# define HEIGHT 500

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*window;
	void		*image;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_env;

typedef struct	s_points
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_points;

typedef struct	s_grid
{
	int			tlx;	//top left x
	int			tly;	//top left y
	int			brx;	//bottom right x
	int			bry;	//bottom right y
	int			scale;	//spacing between lines
	//rotation of grid
	//angle
}				t_grid;

typedef struct	s_line
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_line;

void			line(t_env *env, t_points *pix);
int				handle_key(int key, t_env *env);
void			draw(t_env *env, int x, int y);

#endif
