/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:48:16 by sayar             #+#    #+#             */
/*   Updated: 2022/05/15 16:47:25 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_data
{
	int					nbr_ph;
	int					id;
	int					time_d;
	int					time_e;
	int					time_s;
	int					last_eat;
	int					nbr_eat;
	int					last_eat_f;
	int					eat_f;
	pthread_mutex_t		fork;
	pthread_mutex_t		*print;
	pthread_t			th;
	struct s_data		*next;
}	t_data;

t_data	*profile_init(void);
t_data	*int_args(t_data *profile, char **av);
t_data	*ft_lstnew(t_data *data, pthread_mutex_t *pen);
t_data	*ft_lstlast(t_data *lst);
void	ft_lstadd_back(t_data **lst, t_data *new);
int		ft_atoi(const char *str);
int		ft_time(void);
void	ft_logic(t_data *list);
void	*dead(t_data *profile);
void	*ph_checker(void *args);
void	*ph_logic(void *args);
void	ft_mutex(t_data *list);
void	checker(t_data *list);

#endif