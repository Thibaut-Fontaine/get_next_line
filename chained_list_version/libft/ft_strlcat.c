/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:26:14 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/24 14:12:33 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		k;
	size_t		i;
	size_t		ret;

	ret = ft_strlen(dest) + ft_strlen(src);
	k = 0;
	while (dest[k] != '\0' && n > 0)
	{
		++k;
		--n;
	}
	if (n == 0)
		return (k + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[k] = src[i];
		++i;
		++k;
	}
	dest[k] = '\0';
	return (ret);
}
