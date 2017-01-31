/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:24:04 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/09 01:00:24 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strrchr(const char *s, int c)
{
	size_t		k;

	k = 0;
	while (s[k] != '\0')
		++k;
	while (s[k] != (char)c && k > 0)
		--k;
	if (s[k] != (char)c)
		return (NULL);
	return ((char*)s + k);
}
