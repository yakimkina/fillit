/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:39:57 by enikole           #+#    #+#             */
/*   Updated: 2019/04/24 20:22:08 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			size_of_map(int n)
{
	int		i;

	i = 2;
	while (i * i < n)
		i += 1;
	return (i);
}

void		alg()
{

}
