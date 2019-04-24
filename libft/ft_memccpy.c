/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:54:18 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 15:04:20 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void							*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	unsigned	char			*str1;
	const	unsigned	char	*str2;
	size_t						i;

	i = 0;
	str1 = (unsigned char *)dst;
	str2 = (const unsigned char *)src;
	while (i != n)
	{
		*str1 = *str2;
		if (*str2 == (unsigned char)c)
			return ((void *)str1 + 1);
		str1++;
		str2++;
		i++;
	}
	return (NULL);
}
