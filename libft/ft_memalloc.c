/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:15:02 by enikole           #+#    #+#             */
/*   Updated: 2019/04/11 15:41:32 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if (!size)
		return (NULL);
	if ((str = (void*)malloc(sizeof(void) * (size))) != NULL)
		ft_bzero(str, size);
	return (str);
}
