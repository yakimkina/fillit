/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:30:57 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 21:26:15 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;

	if (s == NULL)
		return (NULL);
	i = 0;
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	if (s[i] == '\0')
		return (ft_strsub(s, i, 0));
	k = ft_strlen(s) - 1;
	while ((s[k] == ' ') || (s[k] == '\n') || (s[k] == '\t'))
		k--;
	return (ft_strsub(s, i, k - i + 1));
}
