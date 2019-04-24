/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:21:55 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 15:05:59 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (size <= d)
		return (size + s);
	while (*dst != '\0')
		dst++;
	i = 0;
	while ((++i < size - d) && (*src != '\0'))
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (d + s);
}
