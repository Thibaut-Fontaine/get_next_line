/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:40:17 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/31 04:29:30 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strfjoin(char **s1, char const *s2)
{
	char	*tmp;
	char	*tmp2;

	if (s1 == NULL || *s1 == NULL || s2 == NULL)
		return (NULL);
	tmp2 = *s1;
	if ((tmp = malloc(ft_strlen(*s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	ft_strcpy(tmp, *s1);
	ft_strcat(tmp, s2);
	tmp[ft_strlen(*s1) + ft_strlen(s2) + 1] = '\0';
	free(tmp2);
	return (tmp);
}
