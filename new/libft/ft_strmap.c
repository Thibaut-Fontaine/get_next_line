/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:41:07 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/19 02:47:37 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
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
		tmp[k] = f(s[k]);
		++k;
	}
	tmp[k] = '\0';
	return (tmp);
}
