/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:47:26 by sayar             #+#    #+#             */
/*   Updated: 2022/05/16 12:43:11 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*profile_iniiiit(t_data *profile, char **av)
{
	profile = profile_init();
	profile = int_args(profile, av);
	return (profile);
}

void	free_lst(t_data *list)
{
	int		i;
	int		loop;
	t_data	*tmp;

	if (!list)
		return ;
	i = 0;
	loop = list->nbr_ph;
	while (i < loop)
	{
		tmp = list->next;
		free(list);
		list = tmp;
		i++;
	}
	list = NULL;
	return ;
}

int	print_init_error(void)
{
	write(2, "Wrong number of arguments\n", 26);
	write(2, "number_of_philosophers\n", 23);
	write(2, "time_to_die\n", 12);
	write(2, "time_to_eat\n", 12);
	write(2, "time_to_sleep\n", 14);
	write(2, "Optional : number_of_times_each_philosopher_must_eat\n", 53);
	return (1);
}

int	main(int ac, char **av)
{
	t_data			*profile;
	t_data			*list;
	pthread_mutex_t	print;
	int				sum;

	list = NULL;
	if (ac < 5 || ac > 6)
		return (print_init_error());
	profile = profile_iniiiit(profile, av);
	if (profile == NULL)
	{
		write(2, "Error init\n", 11);
		return (1);
	}
	sum = profile->nbr_ph;
	profile->id = 1;
	while (sum-- != 0)
	{
		ft_lstadd_back(&list, ft_lstnew(profile, &print));
		profile->id++;
	}
	free(profile);
	ft_logic(list);
	free_lst(list);
	return (0);
}
