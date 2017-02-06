/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:36:22 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/06 04:24:55 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

# define BUFF_SIZE 2000

typedef struct		s_stack
{
	char			*pt;
	char			*buff;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_head
{
	t_stack			*head;
	t_stack			*current;
}					t_head;

int					get_next_line(const int fd, char **line);
int					ft_getlen(t_stack *current);
char				*ft_generate_line(t_stack **head, int len);
t_stack				*ft_generate_new(t_stack *current);

#endif
