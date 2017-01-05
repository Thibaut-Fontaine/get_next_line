/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testbegin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 02:54:48 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/03 04:43:53 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>

int			main()
{
	char	*line;

	get_next_line(8, &line);
	ft_putstr(line);
	ft_putchar('\n');
	free(line);
	get_next_line(5, &line);
	ft_putstr(line);
	ft_putchar('\n');
	char	l;
	while (read (0, &l, 1));
	return (0);
}
