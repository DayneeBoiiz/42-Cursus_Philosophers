/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:29:20 by sayar             #+#    #+#             */
/*   Updated: 2022/05/10 17:05:11 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check(int nbr, int sign)
{
	if (sign == '-')
		return (0);
	else
		return (nbr);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	nbr;
	int		symb;
	int		lock;

	symb = 1;
	i = 0;
	nbr = 0;
	lock = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && lock == 0)
	{
		lock = 1;
		symb = str[i];
		i++;
	}
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (check(nbr, symb));
}
