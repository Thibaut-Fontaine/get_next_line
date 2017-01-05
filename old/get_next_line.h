/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:36:22 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/16 00:55:19 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 15

/*
**  la liste est utilisee de maniere circulaire, parce-que c'est rigolo
*/

typedef struct		s_endl
{
	int				fd;
	char			*s;
	struct s_endl	*next;
}					t_endl;

int					get_next_line(const int fd, char **line);

int					ft_find_nl(char *s);
char				*ft_realloc_str(char *str, size_t size);
t_endl				*ft_get_current(const int fd, t_endl *current);

#endif
