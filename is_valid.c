/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:07:24 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/26 18:42:40 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	fill_index(int *i, int *y, int *m, int *x)
{
	*i = 0;
	*x = 0;
	*y = 0;
	*m = 1;
}

static	int		azobindung(int *str, int x, int y)
{
	int			i;
	int			az;

	az = 0;
	i = 1;
	while (i != 9)
	{
		if (str[i] == x + 1 && str[i + 1] == y)
			az++;
		if (str[i] == x - 1 && str[i + 1] == y)
			az++;
		if (str[i] == x && str[i + 1] == y + 1)
			az++;
		if (str[i] == x && str[i + 1] == y - 1)
			az++;
		i = i + 2;
	}
	return (az);
}

static	int		prufung(int *str)
{
	int			m;
	int			az;

	m = 1;
	az = 0;
	while (m != 9)
	{
		az = az + azobindung(str, str[m], str[m + 1]);
		m = m + 2;
	}
	if (az == 6 || az == 8)
		return (1);
	else
		return (0);
}

static	int		fullen(t_list **blatt, char *buf)
{
	int			i;
	int			x;
	int			y;
	int			m;

	fill_index(&i, &y, &m, &x);
	while (i != 19)
	{
		if (buf[i] == '.' && x < 4 && ++i)
			x++;
		else if (buf[i] == '\n' && y < 4 && x <= 4 && ++y && ++i)
			x = 0;
		else if (buf[i] == '#' && y < 4 && x < 4 && m < 9 && ++i && ++x)
		{
			((int*)((*blatt)->content))[m] = x - 1;
			((int*)((*blatt)->content))[m + 1] = y;
			m = m + 2;
		}
		else
			return (0);
	}
	if ((buf[19] == '\n' && (buf[20] == '\n' || buf[20] == '\0')) &&
			prufung((int*)((*blatt)->content)) == 1)
		return (1);
	return (0);
}

int				lesen(int fd, t_list **list)
{
	char		*buf;
	int			ret;
	int			alfa;
	int			ret2;

	if ((buf = (char*)malloc(sizeof(char) * 22)) == NULL)
		return (0);
	alfa = 'A';
	while ((ret = read(fd, buf, 21)))
	{
		ret2 = ret;
		buf[ret] = '\0';
		if (alfa == '[' || fullen(lst_end_add(list, alfa), buf) == 0)
			return (0);
		alfa++;
		free(buf);
		if ((buf = (char*)malloc(sizeof(char) * 22)) == NULL)
			return (0);
	}
	free(buf);
	if (ret2 == 20)
		return (alfa - 'A');
	return (0);
}
