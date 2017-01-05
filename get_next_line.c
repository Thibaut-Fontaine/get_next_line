/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:49:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/05 01:39:06 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

/*
** cherche le prochain newline dans une string et renvoie son emplacement
** commencant donc a 0, puis 1, 2, 3, etc...
** si il n'y a pas de newline dans la string, renvoie -1
*/

int					ft_find_nl(char *s)
{
	char			*tmp;

	tmp = s;
	while (*s && *s != '\n')
		++s;
	if (*s == 0)
		return (-1);
	return (s - tmp);
}

/*
** - si str n'est pas NULL : malloc de size, copie size caracteres de str
** dans le pt obtenu, NUL-terminate le pt, puis free str
** - si un malloc foire, renvoie NULL
** - si str est NULL, renvoie malloc de size et le memset a un ascii lambda
** ! size ne doit pas compter le 0
*/

char				*ft_realloc_str(char *str, size_t size)
{
	char			*r;

	if (str != NULL)
	{
		if ((r = malloc(size + 1)) == NULL)
			return (NULL);
		ft_strncpy(r, str, size);
		r[size] = 0;
		free(str);
	}
	else
	{
		if ((r = malloc(size + 1)) == NULL)
			return (NULL);
		ft_bzero(r, size);
	}
	return (r);
}

t_endl				*ft_generate_content(const int fd)
{
	t_endl			*tmp;

	if ((tmp = malloc(sizeof(t_endl))) == NULL)
		return (NULL);
	tmp->fd = fd;
	tmp->s = NULL;
	return (tmp);
}

/*
** si le maillon envoye est NULL, renvoie un malloc avec le fd
** si fd est deja present dans un maillon, renvoie ce maillon
** sinon, cree un maillon avec le fd, l'incorpore et le renvoie
** la liste est utilisee de maniere circulaire
*/

t_list				*ft_get_current(const int fd, t_list *current)
{
	int				f_fd;

	if (current == NULL)
	{
		if (!(current = ft_lstnew(ft_generate_content(fd), sizeof(t_endl))))
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
	if (!(current = ft_lstinsert(&current, ft_lstnew(ft_generate_content(fd),
						sizeof(t_endl)), 2)))
		return (NULL);
	return (current);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*current = NULL;

	current = ft_get_current(fd, current);
	return (1);
}
