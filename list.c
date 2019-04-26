/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:38:11 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/26 18:50:40 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	t_list	*end_of_lists(t_list **alst)
{
	t_list		*list;

	if (alst == NULL)
		return (NULL);
	list = (*alst);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void			list_free(t_list **alst)
{
	t_list		*list;
	t_list		*nxt;

	list = (*alst);
	while (list->next != NULL)
	{
		nxt = list;
		while ((nxt->next)->next != NULL)
			nxt = nxt->next;
		free((nxt->next)->content);
		free(nxt->next);
		nxt->next = NULL;
	}
	free(list->content);
	free(list);
}

t_list			**lst_end_add(t_list **alst, int alfa)
{
	t_list		*list;
	t_list		*new;
	int			*str;

	if (alst == NULL)
		return (NULL);
	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((str = (int*)malloc(sizeof(int) * 9)) == NULL)
		return (NULL);
	str[0] = alfa;
	new->content = (void *)str;
	new->next = NULL;
	if ((*alst) == NULL)
	{
		new->next = (*alst);
		(*alst) = new;
		return (alst);
	}
	else
	{
		list = end_of_lists(alst);
		list->next = new;
		return (&(list->next));
	}
}
