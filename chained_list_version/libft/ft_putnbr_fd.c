/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 22:39:40 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/14 22:44:48 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	char	array[11];
	int		k;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-', fd);
		}
		k = -1;
		while (n)
		{
			array[++k] = n % 10 + '0';
			n = n / 10;
		}
		while (k >= 0)
			ft_putchar_fd(array[k--], fd);
	}
}
