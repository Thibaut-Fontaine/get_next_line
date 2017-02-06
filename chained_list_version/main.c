/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 01:27:06 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/06 02:41:03 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		ft_putstr("trop ou pas assez d'arguments\n");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
