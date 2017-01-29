/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:36:37 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/18 17:59:14 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	char		*n_0(char *str)
{
	if ((str = malloc(2)) == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = 0;
	return (str);
}

static	char		*n_min(char *str)
{
	if ((str = malloc(12)) == NULL)
		return (NULL);
	ft_memcpy(str, "-2147483648", 12);
	return (str);
}

static	int			n__(char **str, t_bool *neg, int *n, int *tmp)
{
	int		ret;

	ret = 0;
	*str = NULL;
	*neg = FALSE;
	if (*n < 0)
	{
		if (*n == -2147483648)
		{
			ret = 1;
			*str = (n_min(*str));
		}
		*neg = TRUE;
		*n = -*n;
	}
	else if (*n == 0)
	{
		ret = 1;
		*str = (n_0(*str));
	}
	*tmp = *n;
	return (ret);
}

char				*ft_itoa(int n)
{
	char			*str;
	size_t			k;
	int				tmp;
	t_bool			neg;

	if (n__(&str, &neg, &n, &tmp) == 1)
		return (str);
	k = 0;
	while (tmp)
	{
		tmp = tmp / 10;
		++k;
	}
	if ((str = malloc(k + 1 + neg)) == NULL)
		return (NULL);
	str[k + neg] = '\0';
	if (neg == TRUE)
		str[0] = '-';
	while (k != 0)
	{
		--k;
		str[k + neg] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
