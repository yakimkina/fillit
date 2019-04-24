/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:29:01 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 21:25:57 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * ((int)ft_strlen(s) + 1))) != NULL)
	{
		i = 0;
		while (i < ft_strlen(s))
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
