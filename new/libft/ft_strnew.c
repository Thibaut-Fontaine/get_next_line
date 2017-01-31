/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:08:46 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/14 15:14:57 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strnew(size_t size)
{
	char		*str;

	if ((str = malloc(size * sizeof(char) + 1)) == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
