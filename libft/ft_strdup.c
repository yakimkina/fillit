/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:15:08 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/08 12:24:54 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))) != NULL)
		ft_memcpy((void *)str, (const void *)s1, ft_strlen(s1) + 1);
	return (str);
}
