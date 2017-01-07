/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:49:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/07 22:00:09 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

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

/*
** cette fonction sert a supprimer un maillon de la liste circulaire,
** a la fin de l'utilisation d'un fichier notamment
** mais ce n'est pas indispensable
*/

/*int					ft_del_content(t_list **current)
{
	t_list			*pt;
	int				f_fd;

	free(((t_endl*)((*current)->content))->s);
	f_fd = ((t_endl*)((*current)->content))->fd;
	while ((pt = *current))
	{
		*current = (*current)->next;
		if (((t_endl*)((*current)->content))->fd == f_fd)
			break ;
	}
	pt->next = (*current)->next;
	free((*current)->content);
	return (0);
}*/

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
	unsigned int	len;
	char			*nl;

	current = ft_get_current(fd, current);
	len = BUFF_SIZE + ft_strlen(((t_endl*)(current->content))->s);
	if (!(*line = malloc(len + 1)))
		return (-1);
	ft_strcpy(*line, ((t_endl*)(current->content))->s);
	while ((read(fd, *line + len - BUFF_SIZE, BUFF_SIZE)) == BUFF_SIZE)
	{
		(*line)[len] = '\0';
		if ((nl = strchr(*line, '\n')) != NULL)
		{
			if ((((t_endl*)(current->content))->s = ft_realloc_str(((t_endl*)
					(current->content))->s, ft_strlen(nl + 1) + 1)) == NULL)
				return (-1);
			ft_strcpy(((t_endl*)(current->content))->s, nl + 1);
			return ((*nl = 0) == 0);
		}
		if (!(*line = ft_realloc_str(*line, len += BUFF_SIZE)))
			return (-1);
	}
	return (BUFF_SIZE ? 0 : -1);
}
