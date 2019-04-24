/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:30:16 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 15:21:16 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start,
		size_t len)
{
	char			*str;
	unsigned	int	i;

	if (s == NULL)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) != NULL)
	{
		str[len] = '\0';
		i = start;
		while (len != 0)
		{
			str[i - start] = s[i];
			i++;
			len--;
		}
	}
	return (str);
}
