/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 00:13:49 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/26 18:36:41 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	size_t	ft_nextchar(char const *s, char c)
{
	size_t		k;

	k = 0;
	while (s[k] && s[k] != c)
		++k;
	return (k);
}

static	size_t	ft_count_words(char const *s, char c)
{
	size_t		k;
	size_t		count;

	k = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && (count == 0 || *(s - 1) == c))
			++k;
		++s;
		++count;
	}
	return (k);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**pts;
	size_t		i;
	size_t		n;

	if (s == NULL)
		return (NULL);
	n = 0;
	i = 0;
	if ((pts = (char**)malloc(sizeof(char*) * ft_count_words(s, c) + 1))
			== NULL)
		return (NULL);
	while (n < ft_count_words(s, c))
	{
		while (s[i] == c)
			++i;
		pts[n] = ft_strsub(s, i, ft_nextchar(&(s[i]), c));
		++n;
		i = i + ft_nextchar(&(s[i]), c);
	}
	pts[n] = NULL;
	return (pts);
}
