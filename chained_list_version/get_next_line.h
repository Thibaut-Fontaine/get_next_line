/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:36:22 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/29 01:02:56 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

# define BUFF_SIZE 1000

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
char				*ft_glfb(t_stack **head);
t_stack				*ft_generate_new(t_stack *current);

#endif
