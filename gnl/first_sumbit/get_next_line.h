/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:18:06 by sgorrin           #+#    #+#             */
/*   Updated: 2018/05/03 17:52:07 by snake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"
# define BUFF_SIZE 256

int	get_next_line(const int fd, char **line);

#endif