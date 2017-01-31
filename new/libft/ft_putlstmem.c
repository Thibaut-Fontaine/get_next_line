/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstmem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:43:24 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/25 15:53:25 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_putlstmem(t_list *lst, t_bool carriage_return)
{
	size_t	n;

	while (lst != NULL)
	{
		n = 0;
		while (n < lst->content_size)
		{
			write(1, (lst->content + n), 1);
			++n;
		}
		if (carriage_return == TRUE)
			ft_putchar('\n');
		lst = lst->next;
	}
}
