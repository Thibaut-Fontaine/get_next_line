/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:04:40 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/26 05:18:47 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		((unsigned char*)dest)[k] = ((unsigned char*)src)[k];
		++k;
	}
	return (dest);
}
