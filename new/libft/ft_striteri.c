/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:33:50 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/26 08:21:30 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	k;

	if (s == NULL || f == NULL)
		return ;
	k = 0;
	while (!&(s[k]) || s[k])
	{
		f(k, &s[k]);
		++k;
	}
}
