/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:13:14 by sayar             #+#    #+#             */
/*   Updated: 2022/05/16 16:37:03 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	unlock_forks(t_data *profile)
{
	sem_post(profile->locks->fork);
	sem_post(profile->locks->fork);
}

void	dead(t_data *profile)
{
	sem_wait(profile->locks->print);
	printf("\033[31m");
	printf("%d %d is dead\n", ft_time(), profile->id);
}

void	main_logic(t_data *profile)
{
	while (profile->eat_f == -1 || profile->eat_f--)
	{
		sem_wait(profile->locks->fork);
		sem_wait(profile->locks->print);
		printf("%d %d has taken a fork\n", ft_time(), profile->id);
		sem_post(profile->locks->print);
		sem_wait(profile->locks->fork);
		sem_wait(profile->locks->print);
		printf("%d %d has taken a fork\n", ft_time(), profile->id);
		sem_post(profile->locks->print);
		sem_wait(profile->locks->print);
		printf("%d %d is eating\n", ft_time(), profile->id);
		sem_post(profile->locks->print);
		profile->last_eat = ft_time();
		usleep(profile->time_e * 1000);
		unlock_forks(profile);
		sem_wait(profile->locks->print);
		printf("%d %d is sleeping\n", ft_time(), profile->id);
		sem_post(profile->locks->print);
		usleep(profile->time_s * 1000);
		sem_wait(profile->locks->print);
		printf("%d %d is thinking\n", ft_time(), profile->id);
		sem_post(profile->locks->print);
	}
	exit (0);
}

void	ft_logic(t_data *profile)
{
	int		i;
	int		j;
	pid_t	*pid;
	int		stats;

	i = 0;
	pid = malloc(sizeof(pid_t) * profile->nbr_ph);
	ft_lstlast(profile)->next = profile;
	while (i < profile->nbr_ph)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			write(2, "Error Fork\n", 11);
		if (pid[i] == 0)
			(ft_checker(profile), main_logic(profile));
		usleep(90);
		i++;
		profile = profile->next;
	}
	while (waitpid(-1, &stats, 0) > 0)
		if (WIFEXITED(stats) && WEXITSTATUS(stats) == 1)
			kill_all(pid, profile->nbr_ph);
	free (pid);
}

void	kill_all(pid_t *pid, int len)
{
	while (len--)
	{
		kill(pid[len], SIGTERM);
	}
}
