/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:41:13 by sayar             #+#    #+#             */
/*   Updated: 2022/05/16 16:48:28 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	all_free(t_data *profile, t_data *list, t_locks *locks)
{
	free(profile);
	ft_logic(list);
	free(locks);
	free_lst(list);
}
