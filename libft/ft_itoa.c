/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:56:29 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 15:23:28 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		int_len(int n)
{
	int			l;

	l = 0;
	if (n <= 0)
		l++;
	while (n != 0)
	{
		if (n < 0)
		{
			n = n / 10;
			n = n * (-1);
		}
		else
			n = n / 10;
		l++;
	}
	return (l);
}

char			*ft_itoa(int n)
{
	int			l;
	char		*str;

	l = int_len(n);
	if ((str = (char *)ft_memalloc(sizeof(char) * ((size_t)l + 1))) != NULL)
	{
		if (n == 0)
			str[0] = '0';
		while (n != 0)
		{
			if (n < 0)
			{
				str[--l] = (-1) * (n % 10) + 48;
				n = n / 10;
				n = n * (-1);
				str[0] = '-';
			}
			else
			{
				str[--l] = n % 10 + 48;
				n = n / 10;
			}
		}
	}
	return (str);
}
