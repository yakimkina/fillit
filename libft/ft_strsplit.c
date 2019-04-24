/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:00:27 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/11 15:22:56 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		count_words(char const *s, char c)
{
	size_t			i;
	size_t			k;
	size_t			l;

	l = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c) || (i == 0))
		{
			k = i + 1;
			while ((s[k] != c) && (s[k] != '\0'))
				k++;
			if ((k - i) != 1)
				l++;
			i = k;
		}
	}
	return (l);
}

static	void		word(size_t *k1, size_t *i1, char const *s, char c)
{
	while ((s[*i1] == c) && (s[*i1] != '\0'))
		*i1 = *i1 + 1;
	*k1 = *i1 + 1;
	while ((s[*k1] != c) && (s[*k1] != '\0'))
		*k1 = *k1 + 1;
}

static	size_t		copy(size_t *i1, char *str, char const *s, size_t *k1)
{
	str[*k1 - *i1] = '\0';
	ft_strncpy(str, &s[*i1], (*k1 - *i1));
	*i1 = *k1;
	return (1);
}

static	void		delete(char **str, size_t k)
{
	size_t			i;

	i = 0;
	while (i < k)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

char				**ft_strsplit(char const *s, char c)
{
	size_t			i;
	char			**str;
	size_t			k1;
	size_t			i1;

	if (s == NULL)
		return (NULL);
	i = 0;
	i1 = 0;
	if ((str = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))) != NULL)
	{
		while (i < count_words(s, c))
		{
			word(&k1, &i1, s, c);
			if ((str[i] = (char *)ft_memalloc(sizeof(char) * (k1 - i1 + 1)))
					== NULL)
			{
				delete(str, i);
				return (NULL);
			}
			i += copy(&i1, str[i], s, &k1);
		}
		str[count_words(s, c)] = NULL;
	}
	return (str);
}
