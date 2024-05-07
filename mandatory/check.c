/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:22:46 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/02 19:40:47 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

int	safi_chbe3o(t_philo *philosopher)
{
	int	i;

	i = 0;
	while (i < philosopher[0].data->num_philosophers)
	{
		if (was_not_satisfied(philosopher[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_last_time_eat(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->mutex_last_time_eat);
	if (philosopher->last_time_eat > 0)
	{
		pthread_mutex_unlock(&philosopher->mutex_last_time_eat);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&philosopher->mutex_last_time_eat);
		return (1);
	}
	pthread_mutex_unlock(&philosopher->mutex_last_time_eat);
}

int	check_someone_died(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->mutex_last_time_eat);
	if ((get_current_time()
			- philosopher->last_time_eat) > (unsigned long)philosopher->data->time_to_die)
	{
		pthread_mutex_lock(&philosopher->data->lock_wach_mat);
		philosopher->data->wach_mat = 1;
		pthread_mutex_unlock(&philosopher->data->lock_wach_mat);
		pthread_mutex_unlock(&philosopher->mutex_last_time_eat);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philosopher->mutex_last_time_eat);
		return (0);
	}
	pthread_mutex_unlock(&philosopher->mutex_last_time_eat);
}

int	was_not_satisfied(t_philo philo)
{
	// looock
	if (philo.data->number_of_times_each_philosopher_must_eat == -1)
		return (1);
	if (philo.compt_n_o_t_eat < philo.data->number_of_times_each_philosopher_must_eat)
		return (1);
	return (0);
}

int	check_args(int c, char **v)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	v++;
	if (c == 5 || c == 6)
	{
		while (i < c - 1)
		{
			num = ft_atoi(v[i]);
			if (num <= 0 || num >= 2147483647)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
