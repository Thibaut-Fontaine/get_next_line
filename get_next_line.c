/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:36:14 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/06 00:12:47 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				*ft_realloc(void *mem, size_t size)
{
	if (mem == NULL)
		return (malloc(size));
	ft_memdel(&mem);
	return (mem);
}

int					ft_get_newline(char *str)
{
	int				count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '\n')
			return (count);
		++count;
	}
	return (count);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	int				nl;
	int				count;
	static t_last	last = {0, ""};

	count = 0;
	while ((ret = read(fd, *line, BUFF_SIZE)) == BUFF_SIZE)
	{
		++count;
		*line += BUFF_SIZE;
	}
	if (ret == -1)
		return (-1);
	(*line)[count] = 0;
	if ((nl = ft_get_newline(*line)) == BUFF_SIZE)
		return (0);
	ft_strcpy(last.str, *line + nl);
	return (1);
}
