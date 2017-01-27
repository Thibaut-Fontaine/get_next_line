/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:27:02 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/27 03:47:48 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

/*
** get the next line from buffers, malloc it to fill *line
** if there is no \n, return NULL
*/

char				*ft_glfb(t_stack **head)
{
	t_stack			*current;
	char			*ch;
	char			*line;
	size_t			len;
	char			*line_head;

	current = *head;
	len = 0;
	if (ft_strchr(current->pt, '\n') == NULL)
		len = ft_strlen(current->pt);
	while ((ch = ft_strchr(current->pt, '\n')) == NULL)
	{
		len += BUFF_SIZE;
		if ((current = current->next) == NULL)
			return (NULL);
	}
	len += ch - current->pt;
	line = malloc(len);
	line_head = line;
	while ((ch = ft_strchr((*head)->pt, '\n')) == NULL)
	{
		ft_strcpy(line, (*head)->pt);
		line += ft_strlen((*head)->pt);
		*head = (*head)->next;
	}
	ft_strncpy(line, (*head)->pt, ch - (*head)->pt);
	(*head)->pt = ch + 1;
	return (line_head);
}

t_stack				*ft_generate_new(t_stack *current)
{
	if (current == NULL)
	{
		current = malloc(sizeof(t_stack));
		current->next = NULL;
		current->buff = malloc(BUFF_SIZE + 1);
		current->pt = current->buff;
		return (current);
	}
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_stack));
	current->next->next = NULL;
	current->next->buff = malloc(BUFF_SIZE + 1);
	current->next->pt = current->next->buff;
	return (current->next);
}

int					get_next_line(const int fd, char **line)
{
	static t_head	head = {NULL, NULL};
	int				r;

	while (1)
	{
		head.current = ft_generate_new(head.head);
		if (head.head == NULL)
			head.head = head.current;
		if ((r = read(fd, head.current->buff, BUFF_SIZE)) == -1)
			return (-1);
		if (r == 0 && ft_glfb(&head.current) == NULL)
			return (0);
		if (r < BUFF_SIZE)
			head.current->buff[r++] = '\n'; // attention r ++ !
		head.current->buff[r] = '\0';
		if ((*line = ft_glfb(&head.head)) != NULL)
			return (1);
	}
}
/*
** on read 1 fois
** si r vaut 0, que le buffer est vide et que current->s est vide, return 0
** on stocke buffer dans next de current qui est vide
** on lit current->s
** si on trouve un \n, on deplace le pt static dessus et on return 1
** sinon, on passe au prochain current et on cherche un \n
** si y'en a aucun, on met tout le reste dans line et on return 1
*/
