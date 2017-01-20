/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:06:23 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/20 12:26:40 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char		*ft_realloc_str(char *str, size_t size)
{
	char		*r;

	if (str != NULL)
	{
		if ((r = malloc(size + 1)) == NULL)
			return (NULL);
		ft_strncpy(r, str, size);
		r[size] = 0;
		free(str);
	}
	else
		r = NULL;
	return (r);
}

int				get_next_line(const int fd, char **line)
{
	static char	*s = NULL;
	char		*chr;
	size_t		len;
	int			r;

	if (s == NULL)
		if ((s = ft_memalloc(BUFF_SIZE)) == NULL)
			return (-1);
	r = BUFF_SIZE;
	if ((chr = ft_strchr(s, '\n')) == NULL)
	{
		len = ft_strlen(s);
		while (ft_strchr(s, '\n') == NULL && r == BUFF_SIZE)
		{
			if ((r = read(fd, s + len, BUFF_SIZE)) == -1)
				return (-1);
			if ((s = ft_realloc_str(s, len += BUFF_SIZE)) == NULL)
				return (-1);
		}
	}
	chr = ft_strchr(s, '\n');
	/*if (chr == NULL)
	{
		if (*s != 0)
		{
			*line = ft_memalloc(ft_strlen(s));
			ft_memcpy(*line, s, ft_strlen(s));
			(*line)[ft_strlen(s)] = 0;
			*s = 0;
		}
		else
			return (0);
	}
	else*/

	if (chr == NULL && r < BUFF_SIZE)
		return (0);
	*line = ft_memalloc(chr - s);
	ft_memcpy(*line, s, chr - s);
	(*line)[chr - s] = 0;
	ft_memmove(s, chr + 1, ft_strlen(chr + 1) + 1);
	return (1);
}
