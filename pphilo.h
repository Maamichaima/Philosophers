/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pphilo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:59:11 by cmaami            #+#    #+#             */
/*   Updated: 2024/04/27 21:15:51 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	*forks;
	int				wach_mat;
	pthread_mutex_t	lock_wach_mat;
	size_t			daba;
	pthread_mutex_t print;
}					t_data;

typedef struct s_philo
{
	int				index;
	pthread_t		id;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	mutex_last_time_eat;
	size_t			last_time_eat;
	int				compt_n_o_t_eat;
	t_data			*data;
}					t_philo;

void				is_eating(t_philo *philosopher);
int					ft_usleep(size_t milliseconds, t_data data);
size_t				get_current_time(void);
void				is_sleeping(t_philo *philo);
void				is_thinking(t_philo *philo);
void				*thread_routine(void *data);
int					corpse_check(t_data data);
void				print(char c, t_philo philosopher);
int					was_not_satisfied(t_philo philo);

#endif