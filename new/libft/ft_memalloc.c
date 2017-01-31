/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:31:48 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/22 14:40:24 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			*ft_memalloc(size_t size)
{
	void		*tmp;

	if ((tmp = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
