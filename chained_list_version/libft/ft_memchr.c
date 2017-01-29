/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:42:18 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/22 14:42:24 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	size_t		k;

	k = 0;
	while (k < n && *((unsigned char*)s + k) != (unsigned char)c)
		++k;
	if (k == n)
		return (NULL);
	return ((void*)s + k);
}
