/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:27:02 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/31 04:31:48 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

t_list				*ft_generate_list(const int fd)
{
	t_endl			*tmp;
	t_list			*ret;

	if ((tmp = malloc(sizeof(t_endl))) == NULL)
		return (NULL);
	tmp->fd = fd;
	tmp->s = malloc(1);
	*(tmp->s) = '\0';
	ret = ft_lstnew(tmp, sizeof(t_endl));
	free(tmp);
	return (ret);
}

t_list				*ft_get_current(const int fd, t_list *current)
{
	int				f_fd;

	if (current == NULL)
	{
		if (!(current = ft_generate_list(fd)))
			return (NULL);
		return (current->next = current);
	}
	f_fd = ((t_endl*)(current->content))->fd;
	while ((current = current->next))
	{
		if (((t_endl*)(current->content))->fd == fd)
			return (current);
		if (((t_endl*)(current->content))->fd == f_fd)
			break ;
	}
	if (!(current = ft_lstinsert(&current, ft_generate_list(fd), 2)))
		return (NULL);
	return (current);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*current = NULL;
	char			buff[BUFF_SIZE + 1];
	char			*ch;
	int				r;

	current = ft_get_current(fd, current);
	if (S == NULL)
		S = ft_memalloc(1);
	else if (ft_strchr(S, '\n'))
		ft_memmove(S, ft_strchr(S, '\n') + 1, ft_strlen(ft_strchr(S, '\n')));
	else
		*S = 0;
	while ((r = read(fd, buff, BUFF_SIZE)) != -1)
	{
		buff[r] = '\0';
		S = ft_strfjoin(&S, buff);
		if (r < BUFF_SIZE && *S == 0)
			return (0);
		if ((ch = ft_strchr(S, '\n')) != NULL)
			return (ft_strncpy(*line = ft_strnew(ch - S), S, ch - S) ? 1 : -1);
		if (r < BUFF_SIZE)
			return (ft_strcpy(*line = ft_strnew(ft_strlen(S)), S) ? 1 : -1);
	}
	return (-1);
}
