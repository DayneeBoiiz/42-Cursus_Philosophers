/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:03:00 by sayar             #+#    #+#             */
/*   Updated: 2022/05/16 16:46:23 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	int_locks(t_locks *locks, t_data *profile)
{
	sem_unlink("fork");
	sem_unlink("print");
	locks->fork = sem_open("fork", O_CREAT, 0600, profile->nbr_ph);
	locks->print = sem_open("print", O_CREAT, 0600, 1);
}

t_data	*profile_iniiit(t_data *profile, char **av)
{
	profile = profile_init();
	profile = int_args(profile, av);
	return (profile);
}

int	print_init_error(void)
{
	printf("Wrong Args\n");
	return (1);
}

int	ft_error(void)
{
	write(2, "Error init\n", 11);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*profile;
	t_data	*list;
	t_locks	*locks;
	int		sum;

	list = NULL;
	locks = malloc(sizeof(t_locks));
	if (ac < 5 || ac > 6)
		return (print_init_error());
	profile = profile_iniiit(profile, av);
	if (profile == NULL)
		return (ft_error());
	int_locks(locks, profile);
	sum = profile->nbr_ph;
	profile->id = 1;
	while (sum-- != 0)
	{
		ft_lstadd_back(&list, ft_lstnew(profile, locks));
		profile->id++;
	}
	all_free(profile, list, locks);
}
