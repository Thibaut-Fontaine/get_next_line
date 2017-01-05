/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:49:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/03 06:04:04 by tfontain         ###   ########.fr       */
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

// si un malloc foire renvoyer -1 !

int					get_next_line(const int fd, char **line)
{
	static t_endl	*current = NULL;
	unsigned int	len;
	int				nl;
	int				r;
	t_endl			*tmp;

	current = ft_get_current(fd, current);
	if (current->s != NULL)
	{
		if ((*line =
					malloc((len = ft_strlen(current->s)) + BUFF_SIZE)) == NULL)
			return (-1);
		ft_strcpy(*line, current->s);
		ft_memdel((void**)&(current->s));
	}
	else
	{
		if ((*line = malloc(BUFF_SIZE)) == NULL)
			return (-1);
		len = BUFF_SIZE;
	}
	while ((r = read(fd, *line + len - BUFF_SIZE, BUFF_SIZE)) == 1)
	{
		if ((nl = ft_find_nl(*line)) != -1)
		{
			if ((current->s = malloc(nl + 1)) == NULL)
				return (-1);
			ft_strcpy(current->s, *line + len - BUFF_SIZE);
			return (1);
		}
		if ((*line = ft_realloc_str(*line, len + BUFF_SIZE)) == NULL)
			return (-1);
		len = len + BUFF_SIZE;
	}
	if (r == 0)
	{
		free(current->s);
		if (current != current->next)
			{
				tmp = current->next;
				free(current);
				current = tmp;
			}
		return (0);
	}
	return (-1);
}





/*int					get_next_line(const int fd, char **line)
{
	static t_endl	*current = NULL;
	unsigned int	index;
	int				ret;
	int				nl;

	if ((current = ft_get_current(fd, current)) == NULL)
		return (-1);
	if ((*line = ft_realloc_str(*line, BUFF_SIZE)) == NULL)
		return (-1);
	index = 0;
	while ((ret = read(fd, &((*line)[index]), BUFF_SIZE)) == BUFF_SIZE)
	{
		*line[index + BUFF_SIZE] = 0;
		if ((nl = ft_find_nl(*line)) != -1) // segfault here at the 3rd loop
		{
			current->s = ft_realloc_str(current->s, ft_strlen(&((*line)[nl]))); // pas sur
			ft_memcpy(current->s, &((*line)[nl]), ft_strlen(&((*line)[nl])));
			if ((*line = ft_realloc_str(*line, nl)) == NULL)
				return (-1);
			return (1);
		}
		index = index + BUFF_SIZE;
		if ((*line = ft_realloc_str(*line, index)) == NULL)
			return (-1);
	}
	if (ret == 0)
	{
		//free(current->s); // ?
		return (0);
	}
	return (-1);
}*/

/*
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
}*/