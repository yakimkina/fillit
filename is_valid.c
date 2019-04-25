/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:07:24 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/25 17:18:00 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			list_free(t_list **alst)
{
	t_list		*list;
	t_list		*nxt;

	list = (*alst);
	while (list->next != NULL)
	{
		nxt = list;
		while ((nxt->next)->next != NULL)
			nxt = nxt->next;
		free((nxt->next)->content);
		free(nxt->next);
		nxt->next = NULL;
	}
	free(list->content);
	free(list);
}

t_list			**lst_end_add(t_list **alst, int alfa)
{
	t_list		*list;
	t_list		*new;
	int			*str;

	if (alst == NULL)
		return (NULL);
	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((str = (int*)malloc(sizeof(int) * 9)) == NULL)
		return (NULL);
	str[0] = alfa;
	new->content = (void *)str;
	new->next = NULL;
	if ((*alst) == NULL)
	{
		new->next = (*alst);
		(*alst) = new;
		return (alst);
	}
	else
	{
//		ft_putstr("Make list");
//		write(1, "\n", 1);
		list = end_of_lists(alst);
		list->next = new;
//		ft_putstr("List is made");
//		write(1, "\n", 1);
		return (&(list->next));
	}
}

t_list			*end_of_lists(t_list **alst)
{
	t_list		*list;

	if (alst == NULL)
		return (NULL);
//	ft_putstr("Where is the fucking list?!");
//	write(1, "\n", 1);
	list = (*alst);
	while (list->next != NULL)
		list = list->next;
//	ft_putstr("HERE IT IS");
//	write(1, "\n", 1);
	return (list);
}

void			fill_index(int *i, int *y, int *m, int *x)
{
	*i = 0;
	*x = 0;
	*y = 0;
	*m = 1;
}

int				azobindung(int *str, int x, int y)
{
	int			i;
	int			az;

	az = 0;
	i = 1;
//	ft_putstr("x = ");
//	ft_putnbr(x);
//	ft_putstr("   y  = ");
//	ft_putnbr(y);
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
//	ft_putstr("   a = ");
//	ft_putnbr(az);
//	ft_putstr("  ");
//	write(1, "\n", 1);
	return (az);
}

int				prufung(int *str)
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
//	write(1, "\n", 1);
//	ft_putstr("az = ");
//	ft_putnbr(az);
//	write(1, "\n", 1);
	if (az == 6 || az == 8)
		return (1);
	else
		return (0);
}

int				fullen(t_list **blatt, char *buf)
{
	int			i;
	int			x;
	int			y;
	int			m;

	fill_index(&i, &y, &m, &x);
	while (i != 19)
	{
		if (buf[i] == '.' && x < 4 && ++i)
//		{
//			ft_putstr("Point");
//			write(1, "\n", 1);
			x++;
//		}
		else if (buf[i] == '\n' && y < 4 && x <= 4 && ++y && ++i)
//		{
//			ft_putstr("New line");
//			write(1, "\n", 1);
			x = 0;
//		}
		else if (buf[i] == '#' && y < 4 && x < 4 && m < 9 && ++i && ++x)
		{
//			ft_putstr("Resheto");
//			write(1, "\n", 1);
			((int*)((*blatt)->content))[m] = x - 1;
			((int*)((*blatt)->content))[m + 1] = y;
			m = m + 2;
		}
		else
			return (0);
//		ft_putstr("x = ");
//		ft_putnbr(x);
//		ft_putstr("  y = ");
//		ft_putnbr(y);
//		ft_putstr("  i = ");
//		ft_putnbr(i);
//		ft_putstr("  m = ");
//		ft_putnbr(m);
//		write(1, "\n", 1);
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
		buf[21] = '\0';
//		ft_putstr("ret = ");
//		ft_putnbr(ret);
//		write(1, "\n", 1);
//		ft_putstr(buf);
//		write(1, "\n", 1);
		if (alfa == '[' || fullen(lst_end_add(list, alfa), buf) == 0)
		{
			list_free(list);
			return (0);
		}
		alfa++;
//		ft_putchar(buf[20]);
//		write(1, "\n", 1);
		free(buf);
		if ((buf = (char*)malloc(sizeof(char) * 22)) == NULL)
			return (0);
	}
//	ft_putnbr(ret);
//	write(1, "\n", 1);
	free(buf);
	if (ret2 == 20)
		return (1);
	return (0);
}

int				main(int n, char **str)
{
	int			fd;
	t_list		*l;

	if (n != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	fd = open(str[1], O_RDONLY);
	if (fd == -1)
		return (0);
	if (lesen(fd, &l) == 0)
		ft_putendl("error");
	close (fd);
	return (0);
}
