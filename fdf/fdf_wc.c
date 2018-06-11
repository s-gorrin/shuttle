#include "fdf.h"

int	wc(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i])
		count = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count);
}
