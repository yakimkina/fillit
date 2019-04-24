/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:32:25 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/08 12:22:04 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int								ft_memcmp(const void *s1, const void *s2,
		size_t n)
{
	const	unsigned	char	*str1;
	const	unsigned	char	*str2;
	size_t						i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i != n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		i++;
	}
	return (0);
}
