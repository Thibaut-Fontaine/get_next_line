/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:13:07 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/27 18:23:13 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*dst;
	t_list		*head;

	if ((dst = ft_lstnew(f(lst)->content, f(lst)->content_size)) == NULL)
		return (NULL);
	head = dst;
	lst = lst->next;
	while (lst != NULL)
	{
		if ((dst->next = ft_lstnew(f(lst)->content, f(lst)->content_size))
				== NULL)
			return (NULL);
		lst = lst->next;
		dst = dst->next;
	}
	dst->next = NULL;
	return (head);
}
