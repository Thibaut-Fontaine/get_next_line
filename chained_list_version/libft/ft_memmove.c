/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:10:40 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/17 00:26:04 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		k;

	if (n == 0)
		return (dest);
	if (src < dest)
	{
		while (--n > 0)
			*((unsigned char*)dest + n) = *((unsigned char*)src + n);
		*((unsigned char*)dest + n) = *((unsigned char*)src + n);
	}
	if (src > dest)
	{
		k = 0;
		while (k < n)
		{
			*((unsigned char*)dest + k) = *((unsigned char*)src + k);
			++k;
		}
	}
	return (dest);
}
