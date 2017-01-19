/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 22:01:08 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/19 22:48:50 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "./get_next_line.h"

int			main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int		fd;
	char	*line;
	int		r;
	size_t	k;

	r = 1;
	fd = open(argv[1], O_RDONLY);
	k = 0;
	while ((r = get_next_line(fd, &line)) == 1 || r == -1)
	{
		ft_putstr("=>"); ft_putstr(line); ft_putstr("\n");
	}
	//char l;
	//while (read(0, &l, 1));
	close(fd);
	return (0);
}
