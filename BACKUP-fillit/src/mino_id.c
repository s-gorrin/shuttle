/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mino_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:55:27 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/12 17:13:09 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: checks for pieces where second hash is at +1
** @Param1: the string being checked.
** @Param2: index of first hash in the string.
** @Return: a string of relative # locations in hex or null for invalid.
*/

static t_mino	*one_first(char *mstr, int i)
{
	if (mstr[i + 2] == '#' && mstr[i + 3] == '#')
		return ("0123\0");
	if (mstr[i + 2] == '#' && mstr[i + 5] == '#')
		return ("0125\0");
	if (mstr[i + 2] == '#' && mstr[i + 6] == '#')
		return ("0126\0");
	if (mstr[i + 2] == '#' && mstr[i + 7] == '#')
		return ("0127\0");
	if (mstr[i + 4] == '#' && mstr[i + 5] == '#')
		return ("1256\0");
	if (mstr[i + 5] == '#' && mstr[i + 6] == '#')
		return ("0156\0");
	if (mstr[1 + 5] == '#' && mstr[i + 10] == '#')
		return ("015A\0");
	if (mstr[i + 6] == '#' && mstr[i + 7] == '#')
		return ("0167\0");
	if (mstr[1 + 6] == '#' && mstr[i + 11] == '#')
		return ("016B\0");
	else
		return (NULL);
}

/*
** @Function: checks for pieces where second hash is at +4
** @Param1: the string being checked.
** @Param2: index of first hash in the string.
** @Return: a string of relative # locations in hex or null for invalid.
*/

static t_mino	*four_first(char *mstr, int i)
{
	if (mstr[i + 5] == '#' && mstr[i + 6] == '#')
		return ("1567\0");
	if (mstr[i + 5] == '#' && mstr[i + 9] == '#')
		return ("156A\0");
	if (mstr[i + 5] == '#' && mstr[i + 10] == '#')
		return ("156B\0");
	else
		return (NULL);
}

/*
** @Function: checks for pieces where second hash is at +5
** @Param1: the string being checked.
** @Param2: index of first hash in the string.
** @Return: a string of relative # locations in hex or null for invalid.
*/

static t_mino	*five_first(char *mstr, int i)
{
	if (mstr[i + 6] == '#' && mstr[i + 7] == '#')
		return ("0567\0");
	if (mstr[i + 6] == '#' && mstr[i + 10] == '#')
		return ("056A\0");
	if (mstr[i + 6] == '#' && mstr[i + 11] == '#')
		return ("056B\0");
	if (mstr[i + 9] == '#' && mstr[i + 10] == '#')
		return ("16AB\0");
	if (mstr[i + 10] == '#' && mstr[i + 11] == '#')
		return ("05AB\0");
	if (mstr[i + 10] == '#' && mstr[i + 15] == '#')
		return ("05AF\0");
	else
		return (NULL);
}

/*
** @Function:
** Each possible piece is hard coded in as offsets from first '#' that is found.
** They are pushed out to different functions to pass Norminette.
** @Param1: mino string to be identified.
** @Return: a char *str of hex numbers, or NULL for invalid piece/malloc fail.
** Return is formatted with the top left corner of the mino as place 0.
*/

t_mino			*mino_id(char *minostr)
{
	int		i;
	char	*ret;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(*ret) * 5)))
		return (NULL);
	while (minostr[i] != '#')
		i++;
	if (minostr[i + 1] == '#')
		ret = one_first(minostr, i);
	else if (minostr[i + 3] == '#')
		return ("2567\0");
	else if (minostr[i + 4] == '#')
		ret = four_first(minostr, i);
	else if (minostr[i + 5] == '#')
		five_first(minostr, i);
	else
		return (NULL);
	return (ret);
}
