/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:08:09 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/09 20:46:47 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while ((haystack[i] != '\0') && (i < len))
	{
		if (haystack[i] == needle[0])
		{
			k = 0;
			while (needle[k] != '\0')
			{
				if (haystack[i + k] != needle[k])
					break ;
				k++;
			}
			if ((needle[k] == '\0') && (k + i <= len))
			{
				return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
