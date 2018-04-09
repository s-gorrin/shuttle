#ifndef GNL_H
# define GNL_H
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"
# define BUFF_SIZE 42

int	get_next_line(const int fd, char **line);

#endif
