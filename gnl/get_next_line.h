/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:18:06 by sgorrin           #+#    #+#             */
/*   Updated: 2018/05/10 20:51:34 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"
# define MAX_FD 65536
# define BUFF_SIZE 64

int	get_next_line(const int fd, char **line);

#endif
