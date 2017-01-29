/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:35:26 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/26 02:54:39 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstjoin(t_list *lst1, t_list *lst2)
{
	while (lst1->next != NULL)
		lst1 = lst1->next;
	ft_lstaddend(lst1, lst2);
}
