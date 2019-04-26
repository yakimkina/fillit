/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:39:57 by enikole           #+#    #+#             */
/*   Updated: 2019/04/26 18:08:45 by enikole          ###   ########.fr       */
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

	del_i = ((int*)(list->content))[1] - i;
	del_j = ((int*)(list->content))[2] - j;
	k = 2;
	while (k++ < 8)
	{
		map[i][j] = ((char*)(list->content))[0];
//		ft_putchar(map[i][j]);
		i = ((int*)(list->content))[k] - del_i;
		j = ((int*)(list->content))[++k] - del_j;
	}
	map[i][j] = ((char*)(list->content))[0];
	if (map[i][j] == 'A')
		ft_putchar('A');
//	ft_putchar(map[i][j]);
//	ft_putchar('\n');
}

void		del_map(char **map, t_list *list, int i, int j)
{
	int		del_i;
	int		del_j;
	int		k;

	del_i = ((int*)(list->content))[1] - i;
	del_j = ((int*)(list->content))[2] - j;
	k = 2;
	while (k++ < 8)
	{
		map[i][j] = '.';
		i = ((int*)(list->content))[k] - del_i;
		j = ((int*)(list->content))[++k] - del_j;
	}
	map[i][j] = '.';
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
//	ft_putnbr(sz);
//	ft_putendl(" = sz");
	while (++j < sz)
	{
		i = -1;
		while (++i < sz)
		{
//			ft_putnbr(i);
//			ft_putendl(" = i");
//			ft_putnbr(j);
//			ft_putendl(" = j");
			i1 = i;
			j1 = j;
			del_i = ((int*)(list->content))[1] - i1;
			del_j = ((int*)(list->content))[2] - j1;
//			ft_putnbr(del_i);
//			ft_putendl(" = del_i");
//			ft_putnbr(del_j);
//			ft_putendl(" = del_j");
			k = 2;
			while (i1 < sz && i1 >= 0 && j1 < sz &&
					j1 >= 0 && map[i1][j1] == '.' && k++ < 8)
			{
	//			ft_putendl("HEAR");
				i1 = ((int*)(list->content))[k] - del_i;
				j1 = ((int*)(list->content))[++k] - del_j;
//				ft_putnbr(i1);
//				ft_putendl(" = i1");
//				ft_putnbr(j1);
//				ft_putendl(" = j1");
			}
			if (k == 9 && list->next == NULL)
			{
				fill_map(map, list, i, j);
				return (1);
			}
			else if (k == 9)
			{
				fill_map(map, list, i, j);
//				ft_putendl("STOIIIIII");
				if (!(try_map(sz, map, list->next)))
					del_map(map, list, i, j);
				else
					return (1);
			}
		}
	}
//	ft_putendl("END OF ITARATION");
	return (0);
}

void		make_map(char ***map, int sz)
{
	int		i;
	int		j;

	*map = (char **)malloc(sizeof(char *) * sz);
	i = sz;
	while (i--)
	{
		(*map)[i] = (char *)malloc(sizeof(char) * sz);
		j = sz;
		while (j--)
		{
			(*map)[i][j] = '.';
			ft_putchar((*map)[i][j]);
		}
		ft_putchar('\n');
	}
}

void		alg(int amt, t_list **list)
{
	char	**map;
	int		sz;
	int		i;
	int		j;
	char	c;

	sz = size_of_map(amt * 4);
//	ft_putnbr(sz);
//	ft_putendl(" = sz");
	make_map(&map, sz);
	ft_putendl("MAP OK");
	while (!(try_map(sz, map, (*list))))
	{
		i = sz;
		ft_putendl("uuuuuuuuvelichenie");
		while (i--)
			free(map[i]);
		sz++;
		make_map(&map, sz);
	}
	ft_putendl("TRY MAP OK");
	ft_putchar('\n');
	j = -1;
	while (++j < sz)
	{
		i = -1;
		while (++i < sz)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}
}
