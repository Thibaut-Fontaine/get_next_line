/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:21:27 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/26 08:06:42 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t		len;

	if (*little == '\0')
		return ((char*)big);
	len = ft_strlen(little);
	while (*big && n-- >= len)
	{
		if (*big == *little && ft_memcmp(big, little, len) == 0)
			return ((char*)big);
		++big;
	}
	return (NULL);
}
