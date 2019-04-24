/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:26:40 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 15:14:43 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*str;

	if (!size)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * size)) != NULL)
		ft_bzero((void *)str, size);
	return (str);
}
