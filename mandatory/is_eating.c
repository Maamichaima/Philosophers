/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:02:48 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/02 19:50:35 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

void	is_eating(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->right);
	print('f', philosopher);
	pthread_mutex_lock(philosopher->left);
	print('f', philosopher);
	print('e', philosopher);
	pthread_mutex_lock(&philosopher->mutex_compt_n_o_t_eat);
	philosopher->compt_n_o_t_eat++;
	pthread_mutex_lock(&philosopher->mutex_compt_n_o_t_eat);
	pthread_mutex_lock(&philosopher->mutex_last_time_eat);
	philosopher->last_time_eat = get_current_time();
	pthread_mutex_unlock(&philosopher->mutex_last_time_eat);
	ft_usleep(philosopher->data->time_to_eat, (philosopher->data));
	pthread_mutex_unlock(philosopher->left);
	pthread_mutex_unlock(philosopher->right);
}
