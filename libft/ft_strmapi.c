/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:29:19 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 15:19:56 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strmapi(char const *s,
		char (*f) (unsigned int, char))
{
	unsigned	int		i;
	char				*str;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * ((unsigned int)ft_strlen(s) + 1)))
			!= NULL)
	{
		i = 0;
		while (i < (unsigned int)ft_strlen(s))
		{
			str[i] = f((unsigned int)i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
