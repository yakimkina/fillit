/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:39:50 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 14:57:26 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void							*ft_memmove(void *dst, const void *src,
		size_t len)
{
	unsigned	char			*d;
	const	unsigned	char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d > s)
		ft_memcpy(d, s, len);
	else
		while (len--)
		{
			*d = *s;
			d++;
			s++;
		}
	return (dst);
}
