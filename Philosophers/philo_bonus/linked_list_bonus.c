/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:10:11 by sayar             #+#    #+#             */
/*   Updated: 2022/05/16 16:25:46 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_data	*ft_lstnew(t_data *profile, t_locks *locks)
{
	t_data	*list;

	list = (t_data *)malloc(sizeof(t_data));
	if (!list)
		return (NULL);
	list->nbr_ph = profile->nbr_ph;
	list->id = profile->id;
	list->time_d = profile->time_d;
	list->time_e = profile->time_e;
	list->time_s = profile->time_s;
	list->eat_f = profile->eat_f;
	list->next = NULL;
	list->locks = locks;
	return (list);
}

t_data	*ft_lstlast(t_data *lst)
{
	t_data	*ptr;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	ft_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*end;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	end = ft_lstlast(*lst);
	end->next = new;
}
