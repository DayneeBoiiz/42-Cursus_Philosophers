/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:08:54 by sayar             #+#    #+#             */
/*   Updated: 2022/05/15 16:47:18 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*ft_lstnew(t_data *profile, pthread_mutex_t *print)
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
	list->print = print;
	list->next = NULL;
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

void	ft_logic(t_data *list)
{
	int	i;

	i = 0;
	ft_lstlast(list)->next = list;
	ft_mutex(list);
	while (i < list->nbr_ph)
	{
		pthread_create(&list->th, NULL, &ph_logic, list);
		usleep(90);
		list = list->next;
		i++;
	}
	checker(list);
	i = 0;
	while (i < list->nbr_ph)
	{
		pthread_detach(list->th);
		list = list->next;
		i++;
	}
	pthread_mutex_destroy(&list->fork);
}
