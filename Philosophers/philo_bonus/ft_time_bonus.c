/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:31:32 by sayar             #+#    #+#             */
/*   Updated: 2022/05/12 22:19:55 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_time(void)
{
	struct timeval	current_time;
	int				current;
	static int		prv = 0;
	int				out;

	gettimeofday(&current_time, NULL);
	current = current_time.tv_sec * 1000;
	current += current_time.tv_usec / 1000;
	if (!prv)
		prv = current;
	out = (current - prv);
	return (out);
}
