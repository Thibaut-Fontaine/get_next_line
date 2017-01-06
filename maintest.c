/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:54:11 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/06 03:41:31 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int				main(int argc, char **argv)
{
	if (argc < 2)
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
	int			fd1;
	int			fd2;
	int			fd3;
	int			ret;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	fd3 = open(argv[1], O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd1, &line) * ret;
		ft_putstr(line); ft_putstr("\n");
		free(line);

		ret = get_next_line(fd2, &line) * ret;
		ft_putstr(line); ft_putstr("\n");
		free(line);

		ret = get_next_line(fd3, &line) * ret;
		ft_putstr(line); ft_putstr("\n");
		free(line);
	}

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
