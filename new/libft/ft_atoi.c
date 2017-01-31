/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 00:13:22 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/18 18:11:16 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int				ft_atoi(const char *nptr)
{
	size_t			k;
	int				ret;
	t_bool			neg;

	k = 0;
	ret = 0;
	neg = FALSE;
	while ((8 <= nptr[k] && nptr[k] <= 13) || nptr[k] == 32)
		++k;
	if (nptr[k] == '-' || nptr[k] == '+')
	{
		if (nptr[k] == '-')
			neg = TRUE;
		++k;
	}
	while ('0' <= nptr[k] && nptr[k] <= '9')
	{
		ret = (nptr[k] - '0') + ret * 10;
		++k;
	}
	if (neg)
		ret = -ret;
	return (ret);
}
