/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:01:14 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/02 19:50:01 by cmaami           ###   ########.fr       */
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

int	ft_usleep(size_t milliseconds, t_data *data)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds && !corpse_check(data))
		usleep(500);
	return (0);
}

void *routine_one_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->data->daba = get_current_time();
	pthread_mutex_lock(philo->right);
	printf("%zu %d has taken a fork \n", get_current_time() - philo->data->daba, philo->index);
	ft_usleep(philo->data->time_to_die, (philo->data));
	pthread_mutex_unlock(philo->right);
	printf("\e[31m%zu %d died\e[0m \n", get_current_time() - philo->data->daba, philo->index);
	return NULL;
}

t_philo *init_program(t_data *data, char **v, int c)
{
	t_philo	*p;
	int		i;

	i = 0;
	*data = inisialiser_data(v, c);
	while (i < data->num_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	p = inisialiser_chaque_philo(data);
	return (p);
}

int create_threads(t_philo *p, t_data data)
{
	int i;
	
	if(data.num_philosophers == 1)
	{
		pthread_create(&(p->id), NULL, routine_one_philo, &(p[0]));
		pthread_join((p->id), NULL);
		pthread_mutex_destroy(p->right);
		return (1);
	}
	else
	{
		i = 0;
		p->data->daba = get_current_time();
		while (i < data.num_philosophers)
		{
			pthread_create(&(p[i].id), NULL, thread_routine, &(p[i]));
			i++;
		}
		monitor(p);
		return (0);
	}
}

int check_args(int c, char **v)
{
	int i;
	int num = 0;
	
	i = 0;
	v++;
	if(c == 5 || c == 6)
	{
		while(i < c - 1)
		{
			num = ft_atoi(v[i]);
			if(num <= 0 || num >= 2147483647)
				return 0;
			i++;
		}
		return 1;
	}
	return 0;
}

int	main(int c, char **v)
{
	t_philo	*p;
	int		i;
	t_data	data;

	i = 0;
	if(!check_args(c, v))
		return 0;
	p = init_program(&data, v, c);
	if (create_threads(p, data))
		return 0;
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
