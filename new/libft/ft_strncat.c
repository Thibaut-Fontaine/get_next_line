/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:26:14 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/09 23:23:34 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		k;
	size_t		i;

	k = 0;
	while (dest[k] != '\0')
		++k;
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[k] = src[i];
		++k;
		++i;
	}
	dest[k] = '\0';
	return (dest);
}
