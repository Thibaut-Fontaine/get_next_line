/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:09:21 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/20 20:06:26 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t size)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	return (ft_strncmp(s1, s2, size) == 0);
}
