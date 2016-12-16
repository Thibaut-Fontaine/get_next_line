/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:49:40 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/16 03:35:53 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

/*
** cherche le prochain newline dans une string et renvoie son emplacement
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
** - si str est NULL, renvoie malloc de size
** ! size ne doit pas compter le 0
*/

char				*ft_realloc_str(char *str, size_t size)
{
	char			*r;

	if (str != NULL)
	{
		if ((r = malloc(size + 1)) == NULL)
			return (NULL);
		ft_memcpy(r, str, size);
		r[size] = 0;
		free(str);
	}
	else
	{
		if ((r = malloc(size + 1)) == NULL)
			return (NULL);
	}
	return (r);
}

/*
** si le maillon envoye est NULL, renvoie un malloc avec le fd
** si fd est deja present dans un maillon, renvoie ce maillon
** sinon, cree un maillon avec le fd, l'incorpore et le renvoie
** la liste est utilisee de maniere circulaire
*/

t_endl				*ft_get_current(const int fd, t_endl *current)
{
	int				f_fd;
	void			*tmp;

	if (current == NULL)
	{
		if ((current = malloc(sizeof(t_endl))) == NULL)
			return (NULL);
		current->fd = fd;
		current->s = NULL;
		current->next = current;
		return (current);
	}
	f_fd = current->fd;
	current = current->next;
	while (current->fd != f_fd)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	tmp = current->next;
	if ((current->next = malloc(sizeof(t_endl))) == NULL)
		return (NULL);
	current = current->next;
	current->fd = fd;
	current->s = NULL;
	current->next = tmp;
	return (current);
}

int					get_next_line(const int fd, char **line)
{
	unsigned int	i;
	int				nl;
	static t_endl	*current = NULL;

	current = ft_get_current(fd, current);
	*line = malloc(BUFF_SIZE);
	i = 0;
	while (read(fd, (*line) + i, BUFF_SIZE) == BUFF_SIZE)
	{
		(*line)[i + BUFF_SIZE] = 0;
		if ((nl = ft_find_nl(*line)) != -1)
			break ;
		i += BUFF_SIZE;
		*line = ft_realloc_str(*line, i + BUFF_SIZE);
	}
	if (nl != -1)
	{
		current->s = malloc(sizeof(char) * (nl + 1));
		ft_strncpy(current->s, *line + i, nl);
		*(current->s + nl) = 0;
		return (1);
	}
	return (0);
}
