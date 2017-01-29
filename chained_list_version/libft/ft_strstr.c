/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:21:15 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/26 06:28:33 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strstr(const char *big, const char *little)
{
	size_t		k;

	k = 0;
	if (*big == 0 && *little != 0)
		return (NULL);
	if (*big != 0 && *little != 0)
	{
		while (big[k] != '\0'
				&& ft_strncmp(big + k, little, ft_strlen(little)) != 0)
			++k;
		if (big[k] == '\0')
			return (NULL);
	}
	return ((char*)big + k);
}
