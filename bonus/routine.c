/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:30:55 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/07 21:59:07 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	print(char c, t_philo *philosopher)
{
	sem_wait(philosopher->data->print);
	if (c == 't')
		printf("\e[35m%zu %d is thinking\e[0m\n", get_current_time()
			- philosopher->data->daba, philosopher->index);
	else if (c == 's')
		printf("\e[33m%zu %d is sleeping\e[0m\n", get_current_time()
			- philosopher->data->daba, philosopher->index);
	else if (c == 'f')
		printf("%zu %d has taken a fork \n", get_current_time()
			- philosopher->data->daba, philosopher->index);
	else if (c == 'e')
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
	gettimeofday(&philosopher->data->last_time_eat, NULL);
	// sem_wait(philosopher->lock_compt_n_o_t_eat);
	philosopher->compt_n_o_t_eat++;
	// sem_post(philosopher->lock_compt_n_o_t_eat);
	ft_usleep(philosopher->data->time_to_eat);
	sem_post(philosopher->data->forks);
	sem_post(philosopher->data->forks);
}

void	is_thinking(t_philo *philo)
{
	print('t', philo);
}

void	is_sleeping(t_philo *philo)
{
	print('s', philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	thread_routine(t_philo *philo)
{
	if (philo->index % 2 == 0)
		ft_usleep(60);
	while (1)
	{
		is_eating(philo);
		// sem_wait(philo->lock_compt_n_o_t_eat);
		if (philo->data->number_of_t_eat != -1
			&& (philo->compt_n_o_t_eat == philo->data->number_of_t_eat))
		{
			// sem_post(philo->lock_compt_n_o_t_eat);
			exit(0);
		}
		// sem_post(philo->lock_compt_n_o_t_eat);
		is_sleeping(philo);
		is_thinking(philo);
	}
}
