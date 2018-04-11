#include "hnl.h"

/*
read through storeage until new line, or end, and memcpy that place onto line.
If there was a newline, return that much.
If i = strlen(stor) -> read more and concat onto storage
keep going thoruhg store: 

Only static var should be storage space.

PROBABLY BEST HOW-TO:
first: check and see if there's anything in storage
step through storage to newline, and memcpy that amount to line
shift place after \n to beginning of storage
return
if there is no storage or storage contains no newline,
	write all of storage to line and then erase storage, then
	read BUFF_SIZE more characters and append to storage
	read storage again until \n and do as above. 
	if no \n, repeat previous steps.
Use linked list (or array if that's too hard) of fd's for multiple files

Make storage stuff a helper function so it can be called later in GNL
*/

static int	shipping(char **storage, char **line, size_t i, int ret)
{
	size_t	len;

	if (line[0] == '\0')
		*line = "";
	while ((*storage)[i] != '\0')
	{
		if ((*storage)[i] == '\n' || ret == 0)
		{
			*line = ft_strnjoin((const char*)*line, (const char*)*storage, i);
			i++;
			len = ft_strlen(*storage + i);
			ft_memmove(*storage, *storage + i, len);
			(*storage)[len] = '\0';
			return (1);
		}
		i++;
	}
	if (i == ft_strlen(*storage))
		*line = ft_strnjoin((const char*)*line, (const char*)*storage, i);
	ft_strdel(storage);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int		ret;
	size_t		i;
	char		buf[BUFF_SIZE + 1];
	static char	*storage;

	i = 0;
	if (!line)
		return (-1);
	*line = NULL;
	if (storage && storage[i] != '\0')
	{
		if ((shipping(&storage, line, i, 1)) == 1)
			return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		storage = ft_strnew(ret);
		ft_memcpy(storage, buf, ret);
		if ((shipping(&storage, line, i, ret)) == 1)
			return (1);
	}
	free(storage);
	return (0);
}

int	main(int ac, char **av)
{
	char	*line;
	int		fd;

	if (ac != 2)
	{
		write(2, "usage: gnl source_file\n", 23);
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		write(2, "Failed to open file.\n", 21);
		return (0);
	}
	while (get_next_line((const int)fd, &line))
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
	}
	close(fd);
	free(line);
	return (0);
}
