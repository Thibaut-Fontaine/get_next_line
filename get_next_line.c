/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:49:40 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/06 17:20:36 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int				get_next_line(const int fd, char **line)
{
	char		*str;

	while (read(fd, str, BUFF_SIZE) == BUFF_SIZE);
	return (0);
}
