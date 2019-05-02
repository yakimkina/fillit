/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:39:57 by enikole           #+#    #+#             */
/*   Updated: 2019/04/29 14:41:11 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		fill_map(char **map, t_list *list, t_index ind, char c)
{
	t_index		del;
	int			k;

	del.i = ((int*)(list->content))[1] - ind.i;
	del.j = ((int*)(list->content))[2] - ind.j;
	k = 2;
	while (k++ < 8)
	{
		map[ind.i][ind.j] = c;
		ind.i = ((int*)(list->content))[k] - del.i;
		ind.j = ((int*)(list->content))[++k] - del.j;
	}
	map[ind.i][ind.j] = c;
	return (1);
}

static	int		try_elem(t_list *list, t_index ind, char **map, int sz)
{
	t_index		del;
	int			k;

	k = 2;
	del.i = ((int*)(list->content))[1] - ind.i;
	del.j = ((int*)(list->content))[2] - ind.j;
	while (ind.i < sz && ind.i >= 0 && ind.j < sz && ind.j >= 0 &&
			map[ind.i][ind.j] == '.' && k++ < 8)
	{
		ind.i = ((int*)(list->content))[k] - del.i;
		ind.j = ((int*)(list->content))[++k] - del.j;
	}
	return (k);
}

static	int		try_map(int sz, char **map, t_list *list)
{
	t_index		ind;
	int			k;

	ind.j = -1;
	while (++ind.j < sz && (ind.i = -1))
		while (++ind.i < sz)
		{
			k = try_elem(list, ind, map, sz);
			if (k == 9 && list->next == NULL)
				return (fill_map(map, list, ind, ((char*)(list->content))[0]));
			else if (k == 9)
			{
				fill_map(map, list, ind, ((char*)(list->content))[0]);
				if (!(try_map(sz, map, list->next)))
					fill_map(map, list, ind, '.');
				else
					return (1);
			}
		}
	return (0);
}

static	int		make_map(char ***map, int sz)
{
	int			i;
	int			j;

	if (!(*map = (char **)malloc(sizeof(char *) * sz)))
		return (0);
	i = sz;
	while (i--)
	{
		if (!((*map)[i] = (char *)malloc(sizeof(char) * sz)))
			return (free_map(map, i));
		j = sz;
		while (j--)
			(*map)[i][j] = '.';
	}
	return (1);
}

int				alg(int amt, t_list **list)
{
	char		**map;
	int			sz;
	int			i;
	int			j;

	sz = size_of_map(amt * 4);
	if (!(make_map(&map, sz)))
		return (0);
	while (!(try_map(sz, map, (*list))))
	{
		free_map(&map, sz);
		sz++;
		if (!(make_map(&map, sz)))
			return (0);
	}
	j = -1;
	while (++j < sz)
	{
		i = -1;
		while (++i < sz)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}
	free_map(&map, sz);
	return (1);
}
