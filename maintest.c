/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:54:11 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/06 02:43:00 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int				main(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);
	/*t_list		*current = NULL;

	current = ft_get_current(45, current);
	((t_endl*)(current->content))->s = malloc(5);
	ft_strcpy(((t_endl*)(current->content))->s, "yoyo");
	current = ft_get_current(45, current);
	current = ft_get_current(8, current);
	ft_putnbr(((t_endl*)(current->content))->fd);
	ft_putstr(((t_endl*)(current->content))->s);*/
	char		*line;
	int			fd;

	fd = open(argv[1], O_RDONLY);

	get_next_line(fd, &line);
	ft_putstr("\noutput ->"); ft_putstr(line); ft_putstr("<-\n");
	free(line);
	get_next_line(fd, &line);
	ft_putstr("\noutput ->"); ft_putstr(line); ft_putstr("<-\n");
	close(fd);

	char l;
	while (read(0, &l, 1));
	return (0);
}
