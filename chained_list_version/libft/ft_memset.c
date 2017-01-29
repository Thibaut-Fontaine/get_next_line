/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:43:43 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/08 17:31:04 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		*((unsigned char*)s + k) = (unsigned char)c;
		++k;
	}
	return (s);
}
