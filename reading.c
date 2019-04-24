/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:20:20 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/24 19:12:14 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				massiv(t_list **l, char *buf, int *x, int *y)
{
	int			i;
	int			m;

	i = 0;
	m = 0;
	while (i != 19)
	{
		printf("\ni = %d, x = %d, y = %d, m = %d\n", i, *x, *y, m);
		if (buf[i] == '.' && *x < 4 && ++i)
		{
			*x = *x + 1;
			printf("Point\n");
		}
		else if (buf[i] == '\n' && *y < 4 && *x <= 4 && ++i)
		{
			printf("EOL\n");
			*y = *y + 1;
			*x = 0;
		}
		else if (buf[i] == '#' && *y < 4 && *x < 4 && m < 8 && ++i)
		{
			printf("RESHETO\n");
			((int*)((*l)->content))[m] = *x;
			((int*)((*l)->content))[m + 1] = *y;
			printf("x = %d, y = %d   ", *x, *y);
			m = m + 2;
		}
		else
			return (0);
		printf("\ni = %d, x = %d, y = %d, m = %d\n", i, *x, *y, m);
	}
	if (buf[19] == '\n' && (buf[20] == '\n' || buf[20] == '\0'))
		return (1);
	return (0);	
}

int				reading(int fd, t_list **l)
{
	int			ret;
	char		*buf;
	int			y;
	int			x;
	int			*str;

	if ((buf = (char*)malloc(sizeof(char) * 22)) == NULL)
			return (0);
	while ((ret = read(fd, buf, 21)))
	{
		x = 0;
		y = 0;
		buf[21] = '\0';
		printf("str = |%s|\n", buf);
		str = NULL;
		if ((str = (int*)malloc(sizeof(int) * 8)) == NULL)
			return (0);
		printf("UUUUUUUUUU\n");
		ft_lstadd(l, ft_lstnew(str, sizeof(int*)));
		printf("YEAAAAAAAAAAAAA\n");
		if (massiv(l, buf, &x, &y) == 0)
			return (0);
		printf("\n");
		free(buf);
		if ((buf = (char*)malloc(sizeof(char) * 22)) == NULL)
			return (0);
	}
	free(buf);
	return (1);
}

int				main(int n, char **str)
{
	int			fd;
	t_list		*l;

	(void)n;
	fd = open(str[1], O_RDONLY);
	if (fd == -1)
		return (0);
	if (reading(fd, &l) == 0)
		printf("Not a valid file\n");
	else
		printf("A valid file\n");
	close (fd);
	return (0);
}
