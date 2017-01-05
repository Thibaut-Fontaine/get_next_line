/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:54:11 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/04 23:46:47 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>

int				main()
{
	t_list		*current = NULL;

	current = ft_get_current(45, current);
	((t_endl*)(current->content))->s = malloc(5);
	ft_strcpy(((t_endl*)(current->content))->s, "yoyo");
	current = ft_get_current(45, current);
	current = ft_get_current(8, current);
	ft_putnbr(((t_endl*)(current->content))->fd);
	ft_putstr(((t_endl*)(current->content))->s);
	char l;
	while (read(0, &l, 1));
	return (0);
}
