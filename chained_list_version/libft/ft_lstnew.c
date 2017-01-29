/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:13:17 by tfontain          #+#    #+#             */
/*   Updated: 2016/11/22 20:07:05 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ret;

	if ((ret = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		ret->content = NULL;
		content_size = 0;
	}
	else if ((ret->content = malloc(content_size)) == NULL)
		return (NULL);
	ft_memcpy(ret->content, content, content_size);
	ret->content_size = content_size;
	ret->next = NULL;
	return (ret);
}
