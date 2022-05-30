/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   profile_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:00:40 by sayar             #+#    #+#             */
/*   Updated: 2022/05/15 16:48:14 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*int_args(t_data *profile, char **av)
{
	profile->nbr_ph = ft_atoi(av[1]);
	if (profile->nbr_ph < 1)
		return (NULL);
	profile->time_d = ft_atoi(av[2]);
	if (profile->time_d == 0)
		return (NULL);
	profile->time_e = ft_atoi(av[3]);
	if (profile->time_e == 0)
		return (NULL);
	profile->time_s = ft_atoi(av[4]);
	if (profile->time_s == 0)
		return (NULL);
	if (av[5])
	{
		profile->eat_f = ft_atoi(av[5]);
		if (profile->eat_f == 0)
			return (NULL);
	}
	return (profile);
}

t_data	*profile_init(void)
{
	t_data	*profile;

	profile = (t_data *)malloc(sizeof(t_data));
	if (!profile)
		return (NULL);
	profile->nbr_ph = 0;
	profile->time_d = 0;
	profile->time_e = 0;
	profile->time_s = 0;
	profile->last_eat = 0;
	profile->eat_f = 0;
	return (profile);
}
