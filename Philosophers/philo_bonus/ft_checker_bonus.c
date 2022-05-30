/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:26:45 by sayar             #+#    #+#             */
/*   Updated: 2022/05/18 12:29:59 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ph_checker(void *args)
{
	t_data		*list;
	int			i;
	int			count;

	list = (t_data *)args;
	while (1)
	{
		if ((int)ft_time() - list->last_eat > list->time_d)
		{
			dead(list);
			exit (1);
		}
	}
	return (NULL);
}

void	ft_checker(t_data *profile)
{
	pthread_t	checker;

	pthread_create(&checker, NULL, &ph_checker, profile);
	pthread_detach(checker);
}
