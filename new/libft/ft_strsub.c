/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:24:08 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/18 18:19:46 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tmp;

	if (s == NULL)
		return (NULL);
	if ((tmp = malloc(len + 1)) == NULL)
		return (NULL);
	ft_strncpy(tmp, s + start, len);
	tmp[len] = '\0';
	return (tmp);
}
