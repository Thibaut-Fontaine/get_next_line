/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:02:46 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/08 18:24:41 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strcat(char *dest, const char *src)
{
	size_t		k;
	size_t		i;

	k = 0;
	while (dest[k] != '\0')
		++k;
	i = 0;
	while (src[i] != '\0')
	{
		dest[k] = src[i];
		++k;
		++i;
	}
	dest[k] = src[i];
	return (dest);
}
