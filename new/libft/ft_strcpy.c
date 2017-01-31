/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:11:01 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/08 17:32:18 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strcpy(char *dest, const char *src)
{
	size_t		k;

	k = 0;
	while (src[k] != '\0')
	{
		dest[k] = src[k];
		++k;
	}
	dest[k] = '\0';
	return (dest);
}
