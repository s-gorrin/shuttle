#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	char	*cs; //conversion specifier
	int		i;

	while (format[i])
	{
		if (format[i] = '%')
		{
			cs = format[i + 1];

			// todo: the actual function
		}
		i++;
	}
}


{0, 1, 2}
{s, d, f}
{"word", 42, 3.14}


"hello %d world %f", 42, 3.14

{"hello ", 42, " world ", 3.14}
{s, d, s, f}

todo:
read through format
identify cs, flags


when a % is found, strchr following character with string literal of flags and cs's
call to flag/cs functions and return code to proceed



function returns number of chars printed - so fill to string and then print
	string and return strlen?



