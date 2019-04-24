/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:24:55 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 15:03:16 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void							*ft_memcpy(void *dst,
		const void *src, size_t n)
{
	unsigned	char			*str1;
	const	unsigned	char	*str2;

	str1 = (unsigned char *)dst + n - 1;
	str2 = (const unsigned char *)src + n - 1;
	while (n--)
	{
		*str1 = *str2;
		str1--;
		str2--;
	}
	return ((void *)dst);
}
