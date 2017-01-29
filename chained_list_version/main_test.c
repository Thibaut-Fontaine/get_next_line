/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 03:39:13 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/27 03:49:03 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("il manque un argument\n");
		return (0);
	}
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	ft_putstr(line);
	free(line); ft_putstr("\n");
	get_next_line(fd, &line);
	ft_putstr(line);
	free(line);
	close(fd);
	return (0);
}
