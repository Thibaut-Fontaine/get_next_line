/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_glfb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 23:06:12 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/29 01:24:44 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>
#include <time.h>

char			*grs()
{
	char		*s;
	size_t		i;

	i = 0;
	s = malloc(BUFF_SIZE + 1);
	while (i < BUFF_SIZE)
	{
		if (rand() % 41 == 0)
			s[i] = '\n';
		else
			s[i] = (rand() % 95) + 32;
		++i;
	}
	s[BUFF_SIZE] = 0;
	return (s);
}

int				main()
{
	t_list		*lsthead;
	t_list		*current;
	size_t		k;
	t_head		head;
	char		*line;

	srand(time(NULL));
	lsthead = ft_lstnew(grs(), BUFF_SIZE + 1);
	k = 0;
	while (++k < 8000)
		ft_lstaddend(lsthead, ft_lstnew(grs(), BUFF_SIZE + 1));
	//ft_putlstmem(lsthead, 0);
	current = lsthead;
	while (--k > 0)
	{
		head.current = ft_generate_new(head.head);
		if (head.head == NULL)
			head.head = head.current;
		head.current->buff = current->content;
		current = current->next;
		head.current = head.current->next;
	}
	while (head.head->next && head.head->pt)
	{
		line = ft_glfb(&head.head);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
