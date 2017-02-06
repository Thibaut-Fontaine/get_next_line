/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:27:02 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/07 00:14:36 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

/*
** calculate len of the line
** if there is no \n, return -1
*/

int				ft_getlen(t_stack *current)
{
	char			*ch;
	int			len;

	len = 0;
	if (ft_strchr(current->pt, '\n') == NULL)
		len = ft_strlen(current->pt);
	while ((ch = ft_strchr(current->pt, '\n')) == NULL)
	{
		len += BUFF_SIZE;
		if ((current = current->next) == NULL)
			return (-1);
	}
	return (len += ch - current->pt);
}

/*
** get the next line from buffers, malloc it to fill *line
*/

char				*ft_generate_line(t_stack **head, int len)
{
	char			*ch;
	char			*line;
	char			*line_head;

	line = malloc(len + 1);
	line_head = line;
	while ((ch = ft_strchr((*head)->pt, '\n')) == NULL)
	{
		ft_strcpy(line, (*head)->pt);
		line += ft_strlen((*head)->pt);
		ch = (void*)(*head);
		*head = (*head)->next;
		free((t_stack*)ch);
	}
	ft_strncpy(line, (*head)->pt, (len = ch - (*head)->pt));
	line[len] = 0;
	(*head)->pt = ch + 1;
	return (line_head);
}

/*
** if current is NULL, create a new list with one item
** else, create a new item at the end of the list and link it
*/

t_stack				*ft_generate_new(t_stack *current)
{
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = malloc(sizeof(t_stack));
		current = current->next;
	}
	else
		current = malloc(sizeof(t_stack));
	current->next = NULL;
	*(current->buff) = 0;
	current->pt = current->buff;
	return (current);
}

int						get_next_line(const int fd, char **line)
{
	static t_head		head = {NULL, NULL, 0};
	int					r;
	int					len;

	head.current = ft_generate_new(head.head);
	if (head.head == NULL)
		head.head = head.current;
	while ((len = ft_getlen(head.head)) == -1 && head.end == 0)
	{
		if ((r = read(fd, head.current->buff, BUFF_SIZE)) == -1)
			return (-1);
		if (r < BUFF_SIZE && head.current->buff[r - 1] != '\n')
		{
			head.current->buff[r] = '\n';
			head.current->buff[r + 1] = 0;
			head.end = 1;
			break ;
		}
		head.current->buff[r] = 0;
		head.current = ft_generate_new(head.head);
	}
	if (ft_getlen(head.head) == -1)
		return (0);
	*line = ft_generate_line(&head.head, len);
	return (1);
}

/*
** (1)
** si le maillon n'a pas de \n, creer un nouveau maillon puis read dedans
** -> si le return du read vaut 0 et que *(head.head->pt) == 0 && head.head->next == NULL, return 0
** -> si le return du read est inferieur a BUFF_SIZE, mettre un \n artificiellement puis (GOTO 2)
** -> sinon, (GOTO 1)
** (2)
** ici le maillon a un \n.
** remplir line, puis changer le maillon, free, etc, puis return 1
**
*/

/*int					get_next_line(const int fd, char **line)
{
	static t_head	head = {NULL, NULL};
	int				r;
	size_t			len;

	head.head = ft_generate_new(NULL);
	while (1)
	{
		head.current = ft_generate_new(head.head);
		if ((r = read(fd, head.current->buff, BUFF_SIZE)) == -1)
			return (-1);
		head.current->buff[r] = 0;
		if ((len = ft_getlen(head.head)) != -1)
		{
			*line = ft_generate_line(&head.head, len);
			return (1);
		}
		if (0 < r && r < BUFF_SIZE)
		{
			head.current->buff[len += ft_strlen(head.current->buff)] = '\n';
			head.current->buff[len + 1] = 0;
		} else if (r == 0)
			return (0);
	}
}*/
