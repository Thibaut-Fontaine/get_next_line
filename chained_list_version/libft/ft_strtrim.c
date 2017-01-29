/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:00:11 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/20 23:48:33 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strtrim(char const *s)
{
	char			*tmp;
	const char		*cursor;

	if (s == NULL)
		return (NULL);
	while (s != '\0' && (*s == '\n' || *s == '\t' || *s == ' '))
		++s;
	cursor = s;
	while (*s)
		++s;
	if (cursor < s)
		--s;
	while (cursor < s && (*s == '\n' || *s == '\t' || *s == ' '))
		--s;
	if (s != '\0')
		++s;
	if ((tmp = malloc((s - cursor) + 1)) == NULL)
		return (NULL);
	ft_memcpy(tmp, cursor, (s - cursor));
	tmp[(s - cursor)] = '\0';
	return (tmp);
}
