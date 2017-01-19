/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:06:23 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/19 23:46:44 by tfontain         ###   ########.fr       */
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
	if (r < BUFF_SIZE && chr == NULL)
		return (0);
	*line = ft_memalloc(chr - s);
	ft_memcpy(*line, s, chr - s);
	(*line)[chr - s] = 0;
	ft_memmove(s, chr + 1, ft_strlen(chr + 1) + 1);
	return (1);
}
