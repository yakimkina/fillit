/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:39:57 by enikole           #+#    #+#             */
/*   Updated: 2019/04/26 15:34:16 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			size_of_map(int n)
{
	int		i;

	i = 2;
	while (i * i < n)
		i += 1;
	return (i);
}

void		fill_map(char **map, t_list *list, int i, int j)
{
	int		del_i;
	int		del_j;
	int		k;

	del_i = (list->content)[1] - i;
	del_j = (list->content)[2] - j;
	k = 2;
	while (k++ < 8)
	{
		map[i][j] = (list->content)[0];
		i = (list->content)[k] - del_i;
		j = (list->content)[++k] - del_j;
	}
}

void		del_map(char **map, t_list *list, int i, int j)
{
	int		del_i;
	int		del_j;
	int		k;

	del_i = (list->content)[1] - i;
	del_j = (list->content)[2] - j;
	k = 2;
	while (k++ < 8)
	{
		map[i][j] = '.';
		i = (list->content)[k] - del_i;
		j = (list->content)[++k] - del_j;
	}
}

int			try_map(int sz, char **map, t_list *list)
{
	int		i;
	int		j;
	int		i1;
	int		j1;
	int		k;
	int		del_i;
	int		del_j;

	j = -1;
	while (++j < sz)
	{
		i = -1;
		while (++i < sz)
		{
			i1 = i;
			j1 = j;
			del_i = (list->content)[1] - i1;
			del_j = (list->content)[2] - j1;
			k = 2;
			while (map[i1][j1] == '.' && i1 < sz && i1 >= 0 && j1 < sz &&
					j1 >= 0 && k++ < 8)
			{
				i1 = (list->content)[k] - del_i;
				j1 = (list->content)[++k] - del_j;
			}
			if (k == 9 && list->next == NULL)
				return (1);
			else if (k == 9)
			{
				fill_map(map, list, i, j);
				if (!(try_map(sz, map, list->next)))
					del_map(map, list, i, j);
				else
					return (1);
			}
		}
	}
	return (0);
}

void		alg(int amt, t_list **list)
{
	char	**map;
	int		sz;
	int		i;
	int		j;
	char	c;

	sz = size_of_map(amt);
	map = (char **)malloc(sizeof(char *) * sz);
	i = sz;
	while (i--)
	{
		map[i] = (char *)malloc(sizeof(char) * sz);
		j = sz;
		while (j--)
			mas[i][j] = '.';
	}
	while (!(try_map(sz, map, (*list))))
		sz++;
	while (++j < sz)
	{
		while (++i < sz)
			ft_putchar(map[i][j]);
		ft_putchat('\n');
	}
}
