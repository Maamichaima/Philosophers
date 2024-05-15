/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:08:27 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/07 21:56:50 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_philosophers;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				number_of_t_eat;
	int				*pids;
	sem_t			*forks;
	size_t			daba;
	sem_t			*print;
	sem_t			*sem_last_time_eat;
	struct timeval	last_time_eat;
}					t_data;

typedef struct s_philo
{
	int				index;
	pthread_t		id;
	int				compt_n_o_t_eat;
	t_data			*data;
}					t_philo;

t_philo				*inisialiser(t_data *data);
int					inisialiser_data(t_data *data, char **v, int c);
int					check_args(int c, char **v);
int					ft_atoi(char *str);
void				is_eating(t_philo *philosopher);
size_t				get_current_time(void);
void				ft_usleep(size_t milliseconds);
void				*monitor(void *data);
void				print(char c, t_philo *philosopher);
int					check_someone_died(t_philo *philosopher);
void				routine(t_philo *philosopher);
void				ft_free(t_philo *philo);
void				create_process(t_data *data, t_philo *philo);

#endif