/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:27:02 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/06 05:14:49 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <fcntl.h>

int				main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("usage :");
		ft_putstr(argv[0]);
		ft_putstr(" source_file target_file\n");
		return (-1);
	}
	int			fd1;
	int			fd2;
	t_head		head = {NULL, NULL};
	int			r = BUFF_SIZE;
	char		*line;
	size_t		len;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_CREAT || O_WRONLY, S_IRWXU);
	while (r != 0 && r != -1)
	{
		head.current = ft_generate_new(head.head);
		if (head.head == NULL)
			head.head = head.current;
		r = read(fd1, head.current->buff, BUFF_SIZE);
	}
	while ((len = ft_getlen(head.head)) != -1)
	{
		line = ft_generate_line(&head.head, len);
		write(fd2, line, ft_strlen(line));
		write(fd2, "\n", 1);
		free(line);
	}
	close(fd1);
	close(fd2);
	return (0);
}
