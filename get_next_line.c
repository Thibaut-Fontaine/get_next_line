/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 05:14:19 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/05 06:00:25 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	if ((*line = (char*)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
		return (-1);
	read(fd, *line, BUFF_SIZE);
	free(*line);
	*line = NULL;
	return ();
}
