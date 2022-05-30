/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:50 by sayar             #+#    #+#             */
/*   Updated: 2022/05/18 12:27:05 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checker(t_data *list)
{
	pthread_t	checker;

	pthread_create(&checker, NULL, &ph_checker, list);
	pthread_join(checker, NULL);
	return ;
}

void	unlock_mutex(t_data *profile)
{
	pthread_mutex_unlock(&profile->fork);
	pthread_mutex_unlock(&profile->next->fork);
}

void	lock_first_fork(t_data *profile)
{
	pthread_mutex_lock(&profile->fork);
	pthread_mutex_lock(profile->print);
	printf("%d %d has taken a fork\n", ft_time(), profile->id);
	pthread_mutex_unlock(profile->print);
}

void	*ph_logic(void *args)
{
	t_data	*profile;

	profile = (t_data *)args;
	while (1)
	{
		lock_first_fork(profile);
		pthread_mutex_lock(&profile->next->fork);
		pthread_mutex_lock(profile->print);
		printf("%d %d has taken a fork\n", ft_time(), profile->id);
		pthread_mutex_unlock(profile->print);
		pthread_mutex_lock(profile->print);
		printf("%d %d is eating\n", ft_time(), profile->id);
		pthread_mutex_unlock(profile->print);
		usleep(profile->time_e * 1000);
		profile->last_eat = ft_time();
		profile->last_eat_f++;
		unlock_mutex(profile);
		pthread_mutex_lock(profile->print);
		printf("%d %d is sleeping\n", ft_time(), profile->id);
		pthread_mutex_unlock(profile->print);
		usleep(profile->time_s * 1000);
		pthread_mutex_lock(profile->print);
		printf("%d %d is thinking\n", ft_time(), profile->id);
		pthread_mutex_unlock(profile->print);
	}
}

void	ft_mutex(t_data *list)
{
	int	i;

	i = 0;
	while (i < list->nbr_ph && list->next)
	{
		pthread_mutex_init(list->print, NULL);
		pthread_mutex_init(&list->fork, NULL);
		list = list->next;
		i++;
	}
}
