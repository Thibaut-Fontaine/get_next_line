/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 05:14:19 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/05 08:15:01 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_get_newline(char *str)
{
	int			count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '\n')
			return (count);
		++count;
	}
	return (count);
}

#include <stdio.h> // !
#include <string.h> // inclure libft

int				get_next_line(const int fd, char **line)
{
	int			ret;
	int			c_nl;
	static char	*lst_str = "\0";

	c_nl = 0;
	strcpy(*line, lst_str);
	*line = *line + strlen(lst_str);
	while ((ret = read(fd, *line, BUFF_SIZE)) == BUFF_SIZE)
	{
		(*line)[BUFF_SIZE] = 0;
		//ft_putstr("1");
		if ((c_nl = ft_get_newline(*line)) != BUFF_SIZE - 1)
		{
			//ft_putstr(*line);
			//printf("->%d___", c_nl);
			break ;
		}
		//ft_putstr("2");
		*line += BUFF_SIZE;
	}
	lst_str = malloc();
	strcpy(lst_str, *line + c_nl);
	(*line)[c_nl] = 0;
	if (ret == -1)
		return (-1);
	if (ret < BUFF_SIZE)
		return (0);
	return (1);
}
