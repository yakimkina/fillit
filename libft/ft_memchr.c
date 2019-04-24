/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:11:43 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/08 12:21:27 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void							*ft_memchr(const void *s, int c, size_t n)
{
	const	unsigned	char	*str;
	unsigned	char			sym;
	size_t						i;

	str = (const unsigned char *)s;
	sym = (unsigned char)c;
	i = 0;
	while (i != n)
	{
		if (*str == sym)
			return ((void *)str);
		str++;
		i++;
	}
	return (NULL);
}
