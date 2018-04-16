/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:08:02 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/09 13:12:45 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 && *s1)
	{
		s1 += 1;
		s2 += 1;
	}
	if (!*s1 && !*s2 && *s1 == *s2)
		return (1);
	else
		return (0);
}
