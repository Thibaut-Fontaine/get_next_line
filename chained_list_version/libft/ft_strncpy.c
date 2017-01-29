/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:39:44 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/17 04:46:56 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		k;

	k = 0;
	while (src[k] != '\0' && k != n)
	{
		dest[k] = src[k];
		++k;
	}
	if (k < n)
	{
		while (k < n)
		{
			dest[k] = 0;
			++k;
		}
	}
	return (dest);
}
