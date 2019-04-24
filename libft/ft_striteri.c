/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:28:35 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/10 19:26:25 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned	int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (i < (unsigned int)ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
}
