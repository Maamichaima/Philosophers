/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:36:26 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/10 16:36:31 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	kill_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		kill(data->pids[i], SIGKILL);
		i++;
	}
}

void	wait_and_kill(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->num_philosophers)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			kill_all(data);
			break ;
		}
		i++;
	}
}

void	create_process(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	philo->data->daba = get_current_time();
	while (i < data->num_philosophers)
	{
		data->pids[i] = fork();
		if (data->pids[i] == 0)
		{
			pthread_create(&philo[i].id, NULL, monitor, &philo[i]);
			routine(&philo[i]);
			pthread_join(philo[i].id, NULL);
		}
		i++;
	}
	sem_close(data->print);
	sem_close(data->forks);
	sem_close(data->sem_last_time_eat);
	wait_and_kill(data);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
}
