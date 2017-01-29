/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:36:37 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/14 22:21:24 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_putnbr(int n)
{
	char	array[11];
	int		k;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n == 0)
		ft_putchar('0');
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar('-');
		}
		k = -1;
		while (n)
		{
			array[++k] = n % 10 + '0';
			n = n / 10;
		}
		while (k >= 0)
			ft_putchar(array[k--]);
	}
}
