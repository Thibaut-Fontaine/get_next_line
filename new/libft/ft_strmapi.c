/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:57:15 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/19 02:47:43 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	k;

	if (s == NULL)
		return (NULL);
	if ((tmp = malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	k = 0;
	while (s[k])
	{
		tmp[k] = f(k, s[k]);
		++k;
	}
	tmp[k] = '\0';
	return (tmp);
}
