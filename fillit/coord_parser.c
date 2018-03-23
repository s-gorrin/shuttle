/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:46:14 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/20 22:09:49 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	coord_parser(char a, char x, char y)
{
	int	index;
	char	ap;

	index = 0;
	ap = a - 65;
	while (ap != 0)
	{
		index += 22;
		ap--;
	}
	while (y != 0)
	{
		index += 5;
		y--;
	}
	index += x;
	return (index);
}

int	main(void)
{
	char	a = 'D';
	char	x = 0;
	char	y = 0;

	printf("%d\n", coord_parser(a, x, y));
	return (0);
}
