/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 01:27:06 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/23 02:52:14 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*line;

	if (argc != 2)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		ret = get_next_line(fd, &line);
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
		if (ret == 0 || ret == -1)
			break ;
	}
	close(fd);
	return (EXIT_SUCCESS);
}
