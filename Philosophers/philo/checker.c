/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:48:30 by sayar             #+#    #+#             */
/*   Updated: 2022/05/18 12:25:12 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead(t_data *profile)
{
	printf("\033[31m");
	printf("%d %d is dead\n", ft_time(), profile->id);
	return (NULL);
}

int	eat_count(t_data *list)
{
	if (list->eat_f > 0)
	{
		if (list->last_eat_f >= list->eat_f)
			return (1);
	}
	return (0);
}

void	*ph_checker(void *args)
{
	t_data		*list;
	int			i;
	int			count;

	list = (t_data *)args;
	while (1)
	{
		i = 0;
		count = 0;
		while (i < list->nbr_ph)
		{
			count += eat_count(list);
			if ((int)ft_time() - list->last_eat > list->time_d)
				return (dead(list));
			list = list->next;
			i++;
		}
		if (count >= list->nbr_ph)
			break ;
	}
	pthread_mutex_lock(list->print);
	return (NULL);
}
