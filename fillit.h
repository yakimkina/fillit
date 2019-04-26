/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:08:59 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/26 16:27:07 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <libc.h>
# include "libft/includes/libft.h"
# include <stdio.h>

t_list	*end_of_lists(t_list **alst);
void	alg(int amt, t_list **list);
int		try_map(int sz, char **map, t_list *list);
void	del_map(char **map, t_list *list, int i, int j);
void	fill_map(char **map, t_list *list, int i, int j);
int		size_of_map(int n);

#endif
