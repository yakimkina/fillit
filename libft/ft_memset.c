/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:37:58 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/08 12:14:53 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void					*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	sym;
	unsigned	char	*str;
	size_t				i;

	i = 0;
	sym = (unsigned char)c;
	str = b;
	while (i != len)
	{
		*str = sym;
		i++;
		str++;
	}
	return (b);
}
