/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:05:35 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/17 13:02:34 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*tmp;

	if ((tmp = (t_list*)malloc(sizeof(t_list))) != NULL)
	{
		if (content == NULL)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		else
		{
			if ((tmp->content = (void*)malloc(content_size)) != NULL)
			{
				ft_memcpy(tmp->content, content, content_size);
				tmp->content_size = content_size;
			}
			else
			{
				free(tmp);
				return (NULL);
			}
		}
		tmp->next = NULL;
	}
	return (tmp);
}
