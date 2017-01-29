/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:55:27 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/25 15:58:49 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t			ft_lstlen(t_list *lst)
{
	size_t		len;

	len = 0;
	while (lst != NULL)
	{
		len = lst->content_size + len;
		lst = lst->next;
	}
	return (len);
}
