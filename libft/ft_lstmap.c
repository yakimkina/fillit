/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:48:31 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 14:55:08 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*list;
	t_list	*help;

	if (lst == NULL)
		return (NULL);
	else
	{
		if ((new = (t_list *)malloc(sizeof(t_list))) != NULL)
		{
			new = f(lst);
			lst = lst->next;
			list = new;
			while (lst != NULL)
			{
				if ((help = (t_list *)malloc(sizeof(t_list))) == NULL)
					return (NULL);
				help = f(lst);
				list->next = help;
				list = list->next;
				lst = lst->next;
			}
		}
		return (new);
	}
}
