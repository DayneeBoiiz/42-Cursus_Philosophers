/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:02:02 by sayar             #+#    #+#             */
/*   Updated: 2022/05/16 16:48:58 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_locks
{
	sem_t			*fork;
	sem_t			*print;
}	t_locks;

typedef struct s_data
{
	int				nbr_ph;
	int				id;
	int				time_d;
	int				time_e;
	int				time_s;
	int				last_eat;
	int				nbr_eat;
	int				last_eat_f;
	int				eat_f;
	struct s_locks	*locks;
	struct s_data	*next;
}	t_data;

t_data	*profile_init(void);
t_data	*int_args(t_data *profile, char **av);
void	ft_lstadd_back(t_data **lst, t_data *new);
t_data	*ft_lstlast(t_data *lst);
t_data	*ft_lstnew(t_data *profile, t_locks *locks);
void	ft_logic(t_data *profile);
void	ft_sem_open(t_data *profile);
void	main_logic(t_data *profile);
void	unlock_forks(t_data *profile);
int		ft_atoi(const char *str);
int		ft_time(void);
void	kill_all(pid_t *pid, int len);
void	ft_checker(t_data *profile);
void	dead(t_data *profile);
void	free_lst(t_data *list);
void	all_free(t_data *profile, t_data *list, t_locks *locks);

#endif