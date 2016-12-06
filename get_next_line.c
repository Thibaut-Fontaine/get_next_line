/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:36:14 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/06 11:28:34 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

t_list				*ft_check_fd(t_list *lst, const int fd)
{
	while (lst != NULL)
	{
		if (*((int*)lst->content) == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	int				nl;
	int				count;
	t_list			*pt;
	static t_list	*head;

	if ((pt = ft_check_fd(head, fd)) == NULL)
	{
		ft_lstadd(&head, ft_lstnew(&fd, sizeof(int*)));
		pt = head;
	}
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
	ft_strcpy(pt->content, *line + nl);
	return (1);
}
