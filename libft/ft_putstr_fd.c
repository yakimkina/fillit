/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:33:34 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/10 15:58:37 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = -1;
	while (++i < (int)ft_strlen(s))
		ft_putchar_fd(s[i], fd);
}
