/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pphilo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:59:11 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/03 10:04:29 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPHILO_H
# define PPHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_philosophers;
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_t_eat;
	pthread_mutex_t	*forks;
	int				is_died;
	pthread_mutex_t	lock_is_died;
	size_t			now;
	pthread_mutex_t	print;
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
	pthread_mutex_t	mutex_compt_n_o_t_eat;
	t_data			*data;
}					t_philo;

void				is_eating(t_philo *philosopher);
int					ft_usleep(size_t milliseconds, t_data *data);
size_t				get_current_time(void);
void				is_sleeping(t_philo *philo);
void				is_thinking(t_philo *philo);
void				*thread_routine(void *data);
int					corpse_check(t_data *data);
void				print(char c, t_philo *philosopher);
int					was_not_satisfied(t_philo *philo);
t_philo				*inisialiser_chaque_philo(t_data *data);
t_data				inisialiser_data(char **v, int c);
int					check_someone_died(t_philo *philosopher);
int					check_last_time_eat(t_philo *philosopher);
int					all_satisfied(t_philo *philosopher);
void				monitor(t_philo *philosopher);
int					ft_atoi(char *str);
void				ft_free(t_philo *philosopher);
t_philo				*init_program(t_data *data, char **v, int c);
int					check_args(int c, char **v);
void				*routine_one_philo(void *data);
int					create_threads(t_philo *p, t_data data);

#endif