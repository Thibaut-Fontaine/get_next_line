/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:27:02 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/24 14:36:21 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int				get_next_line(const int fd, char **line)
{
	static char	*s = NULL;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	char		*ch;
	int			r;

	if (s == NULL)
		s = ft_memalloc(1);
	else
		ft_memmove(s, ft_strchr(s, '\n') + 1, ft_strlen(ft_strchr(s, '\n')));
	while ((r = read(fd, buff, BUFF_SIZE)) != -1)
	{
		buff[r] = '\0';
		tmp = s;
		s = ft_strjoin(s, buff);
		free(tmp);
		if ((ch = ft_strchr(s, '\n')) != NULL)
			return (ft_strncpy(*line = ft_strnew(ch - s), s, ch - s) ? 1 : -1);
		if (r < BUFF_SIZE)
			return (ft_strcpy(*line = ft_strnew(ft_strlen(s)), s) ? 0 : -1);
	}
	return (-1);
}

/*
** Il reste un probleme a eliminer :
** ce gnl renvoie 1 une fois de moins de ce qu'il devrait
** (autrement dit il renvoie 0 trop tot)
*/
