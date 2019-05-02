/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:08:59 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/28 18:40:33 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <libc.h>
# include "libft/includes/libft.h"
# include <stdio.h>

typedef struct			s_index
{
	int					i;
	int					j;
}						t_index;

int						lesen(int fd, t_list **list);

void					list_free(t_list **alst);
t_list					**lst_end_add(t_list **alst, int alfa);

int						size_of_map(int n);
int						free_map(char ***map, int i);

int						alg(int amt, t_list **list);

#endif
