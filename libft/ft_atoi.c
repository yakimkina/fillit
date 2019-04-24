/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnigellu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:08:36 by bnigellu          #+#    #+#             */
/*   Updated: 2019/04/08 15:21:39 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_atoi(const char *str)
{
	long	int	i;
	long	int	res;
	long	int	sign;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\f'
			|| str[i] == '\t' || str[i] == '\v' || str[i] == '\b')
		i++;
	if (str[i] == '-')
		sign = -1;
	else if (str[i] != '+')
		i--;
	while ((str[++i] >= '0') && (str[i] <= '9'))
	{
		if ((res < 0 && sign == 1) || (res != res * 10 / 10 && sign == 1))
			return (-1);
		else if ((res < 0 && sign == -1) || (res != res * 10 / 10
					&& sign == -1))
			return (0);
		res = res * 10 + (str[i] - 48);
	}
	return ((int)res * sign);
}
