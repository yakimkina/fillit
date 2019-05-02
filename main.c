/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:33:16 by bnigellu          #+#    #+#             */
/*   Updated: 2019/05/01 17:47:53 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int n, char **str)
{
	int		fd;
	t_list	*l;
	int		les;

	if (n != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	fd = open(str[1], O_RDONLY);
	if (fd == -1)
		return (0);
	l = NULL;
	les = lesen(fd, &l);
	if (les == 0 || !(alg(les, &l)))
		ft_putendl("error");
	list_free(&l);
	close(fd);
	return (0);
}
