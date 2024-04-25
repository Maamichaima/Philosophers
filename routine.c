/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:47:34 by cmaami            #+#    #+#             */
/*   Updated: 2024/04/25 19:40:53 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

void	print(char c, t_philo philosopher)
{
	size_t	temps;

	temps = get_current_time() - philosopher.data->daba;
	if (c == 't' && !corpse_check(*(philosopher.data)))
		printf("\e[31m%zu philo number %d is thinking\e[0m\n", temps,
			philosopher.index);
	else if (c == 's' && !corpse_check(*(philosopher.data)))
		printf("\e[33m%zu le philo number %d is sleeping\e[0m\n", temps,
			philosopher.index);
	else if (c == 'r' && !corpse_check(*(philosopher.data)))
		printf("%zu philo number %d has taken a right fork \n", temps,
			philosopher.index);
	else if (c == 'l' && !corpse_check(*(philosopher.data)))
		printf("%zu philo number %d has taken a left fork \n", temps,
			philosopher.index);
	else if (c == 'e' && !corpse_check(*(philosopher.data)))
		printf("\e[32m%zu philo number %d is eating\e[0m \n", temps,
			philosopher.index);
}

int	corpse_check(t_data data)
{
	int	b;

	pthread_mutex_lock(&data.lock_wach_mat);
	b = (data.wach_mat == 1);
	pthread_mutex_unlock(&data.lock_wach_mat);
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
		ft_usleep(500, *(philosopher->data));
	while (!corpse_check(*(philosopher->data)))
	{
		is_eating(philosopher);
		is_sleeping(philosopher);
		is_thinking(philosopher);
	}
	return (NULL);
}
