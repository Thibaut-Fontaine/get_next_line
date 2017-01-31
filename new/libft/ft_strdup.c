/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:53:03 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/18 18:01:14 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strdup(const char *s)
{
	char		*ret;
	size_t		k;

	if ((ret = (char*)malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	k = 0;
	while (s[k] != '\0')
	{
		ret[k] = s[k];
		++k;
	}
	ret[k] = '\0';
	return (ret);
}
