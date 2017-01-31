/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 03:05:07 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/26 04:09:46 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstinsert(t_list **dst, t_list *lst, size_t position)
{
	size_t	count;
	t_list	*tmp;

	if (position <= 1)
		ft_lstadd(dst, lst);
	else
	{
		tmp = *dst;
		count = 2;
		while (count < position && tmp->next != NULL)
		{
			tmp = tmp->next;
			++count;
		}
		lst->next = tmp->next;
		tmp->next = lst;
	}
	return (lst);
}
