/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:15:17 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/18 18:40:55 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strchr(const char *s, int c)
{
	size_t		k;

	k = 0;
	while (s[k] != (char)c && s[k] != '\0')
		++k;
	if (s[k] != (char)c)
		return (NULL);
	return ((char*)s + k);
}
