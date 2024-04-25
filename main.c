/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:01:14 by cmaami            #+#    #+#             */
/*   Updated: 2024/04/25 19:47:19 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds, t_data data)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds && !corpse_check(data))
		usleep(500);
	return (0);
}

void	monitor(t_philo *philosopher)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < philosopher->data->num_philosophers
			&& philosopher->last_time_eat > 0)
		{
			if ((get_current_time()
					- philosopher->last_time_eat) > (unsigned long)philosopher->data->time_to_die)
			{
				pthread_mutex_lock(&philosopher->data->lock_wach_mat);
				philosopher->data->wach_mat = 1;
				printf("le philo number %d is die\n", philosopher->index);
				pthread_mutex_unlock(&philosopher->data->lock_wach_mat);
				break ;
			}
			i++;
		}
		if (corpse_check(*(philosopher->data)))
			break ;
		i = 0;
	}
}

t_philo	*inisialiser_chaque_philo(t_data data)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = malloc(sizeof(t_philo) * data.num_philosophers);
	if (!p)
		return (NULL);
	while (i < data.num_philosophers)
	{
		p[i].data = &data;
		p[i].index = i + 1;
		p[i].right = &data.forks[i];
		p[i].left = &data.forks[(i + 1) % data.num_philosophers];
		pthread_mutex_init(&p[i].mutex_last_time_eat, NULL);
		i++;
	}
	return (p);
}

void	inisialiser_data(t_data *data, char **v)
{
	data->num_philosophers = atoi(v[1]);
	data->time_to_die = atoi(v[2]);
	data->time_to_eat = atoi(v[3]);
	data->time_to_sleep = atoi(v[4]);
	data->number_of_times_each_philosopher_must_eat = atoi(v[5]);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	data->wach_mat = 0;
	pthread_mutex_init(&data->lock_wach_mat, NULL);
	data->daba = get_current_time();
}

int	main(int c, char **v)
{
	t_philo	*p;
	int		i;
	t_data	data;

	p = NULL;
	i = 0;
	(void)c;
	inisialiser_data(&data, v);
	while (i < data.num_philosophers)
	{
		pthread_mutex_init(&data.forks[i], NULL);
		i++;
	}
	p = inisialiser_chaque_philo(data);
	i = 0;
	while (i < data.num_philosophers)
	{
		pthread_create(&(p[i].id), NULL, thread_routine, &(p[i]));
		i++;
	}
	monitor(p);
	i = 0;
	while (i < data.num_philosophers)
	{
		pthread_join(p[i].id, NULL);
		i++;
	}
	i = 0;
	while (i < data.num_philosophers)
	{
		pthread_mutex_destroy(&data.forks[i]);
		i++;
	}
	return (0);
}
