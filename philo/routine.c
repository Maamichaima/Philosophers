/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:47:34 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/02 23:01:06 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

void	print(char c, t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->data->print);
	if (c == 't' && !corpse_check(philosopher->data))
		printf("\e[35m%zu %d is thinking\e[0m\n", get_current_time()
			- philosopher->data->now, philosopher->index);
	else if (c == 's' && !corpse_check(philosopher->data))
		printf("\e[33m%zu %d is sleeping\e[0m\n", get_current_time()
			- philosopher->data->now, philosopher->index);
	else if (c == 'f' && !corpse_check(philosopher->data))
		printf("%zu %d has taken a fork \n", get_current_time()
			- philosopher->data->now, philosopher->index);
	else if (c == 'e' && !corpse_check(philosopher->data))
		printf("\e[32m%zu %d is eating\e[0m \n", get_current_time()
			- philosopher->data->now, philosopher->index);
	else if (c == 'd')
		printf("\e[31m%zu %d died\e[0m \n", get_current_time()
			- philosopher->data->now, philosopher->index);
	pthread_mutex_unlock(&philosopher->data->print);
}

int	corpse_check(t_data *data)
{
	int	b;

	pthread_mutex_lock(&data->lock_is_died);
	b = (data->is_died == 1);
	pthread_mutex_unlock(&data->lock_is_died);
	return (b);
}

void	*thread_routine(void *data)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)data;
	pthread_mutex_lock(&philosopher->mutex_last_time_eat);
	philosopher->last_time_eat = get_current_time();
	pthread_mutex_unlock(&philosopher->mutex_last_time_eat);
	if (philosopher->index % 2 == 0)
		ft_usleep(60, (philosopher->data));
	while (!corpse_check(philosopher->data) && was_not_satisfied(philosopher))
	{
		is_eating(philosopher);
		is_sleeping(philosopher);
		is_thinking(philosopher);
	}
	return (NULL);
}

void	*routine_one_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->data->now = get_current_time();
	pthread_mutex_lock(philo->right);
	printf("%zu %d has taken a fork \n", get_current_time() - philo->data->now,
		philo->index);
	ft_usleep(philo->data->time_to_die, (philo->data));
	pthread_mutex_unlock(philo->right);
	printf("\e[31m%zu %d died\e[0m \n", get_current_time() - philo->data->now,
		philo->index);
	return (NULL);
}
