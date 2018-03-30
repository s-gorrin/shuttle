#inlcude "hnl.h"

/*
read thorught storeage until new line, or end, and memcpy that place onto line.
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
	write all of storage to line and then erace storage, then
	read BUFF_SIZE more characters and append to storage
	read storage again until \n and do as above. 
	if no \n, repeat previous steps.

Use linked list (or array if that's too hard) of fd's for multiple files
*/


int	get_next_line(const int fd, char **line)
{
	int			ret;
	int			i;
	int			j;
	char		buf[BUFF_SIZE + 1];
	static char	*storage;

	j = i;
	if (!line)
		return (-1);
	*line = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		while (buf[j] != '\n' && j != ret)
			j++;
		if (buf[j] == '\n')
		{
			memcpy(*line, (buf + i), (j - i));
			i = j + 1;
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*next_line;
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
		return (NULL);
	}
	next_line = get_next_line((const int)fd, line);
	return (0);
}
