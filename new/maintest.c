/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:45:15 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/10 23:05:01 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define TEST_GNL

#ifdef TEST_GNL

int					main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int				fd;
	char			*line;
	fd = open(argv[1], O_RDONLY);

	get_next_line(fd, &line);
	ft_putstr("==> |");/* ft_putstr(line); ft_putstr("| <==\n");
	free(line);

	get_next_line(fd, &line);
	ft_putstr("==> |"); ft_putstr(line); ft_putstr("| <==\n");
	free(line);

	get_next_line(fd, &line);
	ft_putstr("==> |"); ft_putstr(line); ft_putstr("| <==\n");
	free(line);*/

	close(fd);
	return (0);
}

#endif

#ifdef TEST_CURRENT

t_list				*ft_test_current(int const fd, char *s)
{
	static t_list	*current = NULL;

	current = ft_get_current(fd, current);
	((t_endl*)(current->content))->s =
		ft_realloc_str(((t_endl*)(current->content))->s, ft_strlen(s));
	ft_strcpy(((t_endl*)(current->content))->s, s);
	return (current);
}

int					main()
{
	int				k;
	t_list			*maillon;

	k = 0;
	while (k < 20)
	{
		maillon = ft_test_current((k % 10 + 1), "salut test chaine"); // 1 a 10
		printf("%d, %s, fd : %d\n", k, ((t_endl*)(maillon->content))->s, ((t_endl*)(maillon->content))->fd);
		++k;
	}
	k = 0;
	while (k < 20)
	{
		maillon = ft_test_current((k % 10 + 1), "remplacement ll test test"); // 1 a 10
		printf("%d, %s, fd : %d\n", k, ((t_endl*)(maillon->content))->s, ((t_endl*)(maillon->content))->fd);
		++k;
	}
	char l;
	while (read(0, &l, 1) == 1);
	return (EXIT_SUCCESS);
}

#endif
