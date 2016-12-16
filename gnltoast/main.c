/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 00:18:49 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/16 06:24:47 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"

#define main1

#ifdef main1
int				main(int argc, char **argv) // test get_next_line
{
	if (argc != 2)
		return (0);
	char		*buffer;
	int			fd;

	fd = 0;
	fd = open(*argv, O_RDONLY);
	ft_putstr("fd : ");
	ft_putnbr(fd);
	ft_putchar('\n');
	buffer = malloc(1);
	for (int k = 0 ; k < 10; ++k)
	{
		ft_putnbr(get_next_line(fd, &buffer));
		ft_putchar('\n');
		ft_putstr(buffer);
		ft_putchar('\n');
	}
	close(fd);
	return (0);
}
#endif

#ifdef main2
int				main() // test ft_find_nl
{
	ft_putnbr(ft_find_nl("0123456789\n0123456789"));
	return (0);
}
#endif

#ifdef main3
int			main() // test ft_realloc_str
{
	char	*str;

	str = malloc(6);
	ft_strcpy(str, "yoyo\n");
	str = ft_realloc_str(str, 11);
	ft_strcpy(str, "123456789\n");
	ft_putstr(str);
	return (0);
}
#endif

#ifdef main4

void			ft_display_endl(t_endl *current)
{
	int			f_fd;

	f_fd = current->fd;
	current = current->next;
	while (current->fd != f_fd)
	{
		ft_putstr("->fd : ");
		ft_putnbr(current->fd);
		ft_putchar('\n');
		ft_putstr("->s  : ");
		if (current->s != NULL)
			ft_putstr(current->s);
		ft_putchar('\n');
		current = current->next;
	}
	ft_putnbr(f_fd);
}

int				main()
{
	t_endl		*current;

	current = NULL;
	current = ft_get_current(485, current);
	current->s = malloc(6);
	ft_strcpy(current->s, "toast");
	current = ft_get_current(84, current);
	current = ft_get_current(47, current);
	current = ft_get_current(485, current);
	current = ft_get_current(47, current);
	current = ft_get_current(2, current);
	current->s = malloc(8);
	ft_strcpy(current->s, "toaster");
	current = ft_get_current(5, current);
	current = ft_get_current(8, current);
	ft_display_endl(current);
	return (0);
}
#endif
