/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:02:48 by cmaami            #+#    #+#             */
/*   Updated: 2024/04/25 17:39:02 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

void	is_eating(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->right);
	print('r', *philosopher);
	// printf("philo number %d has taken a right fork \n", philosopher->index);
	pthread_mutex_lock(philosopher->left);
	print('l', *philosopher);
	print('e', *philosopher);
	// printf("philo number %d has taken a left fork \n", philosopher->index);
	// printf("\e[32mphilo number %d is eating\e[0m \n", philosopher->index);
	pthread_mutex_lock(&philosopher->mutex_last_time_eat);
	philosopher->last_time_eat = get_current_time();
	pthread_mutex_unlock(&philosopher->mutex_last_time_eat);
	ft_usleep(philosopher->data->time_to_eat, *(philosopher->data));
	pthread_mutex_unlock(philosopher->left);
	pthread_mutex_unlock(philosopher->right);
}
