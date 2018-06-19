#ifndef FDF_H
# define FDF_H
# include "minilibx_macos_10.11/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define GRN 0x2eb82e
# define LAV 0xaa99ee
# define WIDTH 500
# define HEIGHT 500

typedef struct	s_node
{
	float		x;
	float		y;
	float		z;
	int			total_x;
	int			total_y;
}				t_node;

typedef	struct	s_check_in
{
	int			fd;
	int			y;
	int			x;
	int			mx;
	int			my;
}				t_check_in;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*window;
	void		*image;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			color;
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
	int			x_scale;	//spacing between x points
	int			y_scale;	//spacing between y points
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
int				wc(char const *s, char c);
t_node			*read_input(char *filename);
void			point_grid(t_env *env, t_grid *grid);

#endif
