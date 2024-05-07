/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:30:55 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/07 14:27:52 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	print(char c, t_philo *philosopher)
{
	sem_wait(philosopher->data->print);
	if (c == 't')// && !corpse_check(philosopher->data))
		printf("\e[35m%zu %d is thinking\e[0m\n", get_current_time()
			- philosopher->data->daba, philosopher->index);
	else if (c == 's')// && !corpse_check(philosopher->data))
		printf("\e[33m%zu %d is sleeping\e[0m\n", get_current_time()
			- philosopher->data->daba, philosopher->index);
	else if (c == 'f')// && !corpse_check(philosopher->data))
		printf("%zu %d has taken a fork \n", get_current_time()
			- philosopher->data->daba, philosopher->index);
	else if (c == 'e')// && !corpse_check(philosopher->data))
		printf("\e[32m%zu %d is eating\e[0m \n", get_current_time()
			- philosopher->data->daba, philosopher->index);
	else if (c == 'd')
	{
		printf("\e[31m%zu %d died\e[0m \n", get_current_time()
			- philosopher->data->daba, philosopher->index);
		return ;
	}
	sem_post(philosopher->data->print);
}

void	is_eating(t_philo *philosopher)
{
	sem_wait(philosopher->data->forks);
	print('f', philosopher);
	sem_wait(philosopher->data->forks);
	print('f', philosopher);
	print('e', philosopher);
	philosopher->compt_n_o_t_eat++; // mutex
	sem_wait(philosopher->mutex_last_time_eat);
	philosopher->last_time_eat = get_current_time();
	sem_post(philosopher->mutex_last_time_eat);
	ft_usleep(philosopher->data->time_to_eat, (philosopher->data));
	sem_post(philosopher->data->forks);
	sem_post(philosopher->data->forks);
}