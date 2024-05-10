/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:19:28 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/02 22:25:03 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

int	ft_atoi(char *str)
{
	long	nb;
	int		i;
	int		signe;

	i = 0;
	nb = 0;
	signe = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10;
		nb += str[i] - '0';
		i++;
	}
	return (signe * nb);
}

t_philo	*inisialiser_chaque_philo(t_data *data)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = malloc(sizeof(t_philo) * data->num_philosophers);
	if (!p)
		return (NULL);
	while (i < data->num_philosophers)
	{
		p[i].data = data;
		p[i].index = i + 1;
		p[i].right = &data->forks[i];
		p[i].left = &data->forks[(i + 1) % data->num_philosophers];
		pthread_mutex_init(&p[i].mutex_last_time_eat, NULL);
		p[i].compt_n_o_t_eat = 0;
		p[i].last_time_eat = 0;
		i++;
	}
	return (p);
}

t_data	inisialiser_data(char **v, int c)
{
	t_data	data;

	data.num_philosophers = ft_atoi(v[1]);
	data.time_to_die = ft_atoi(v[2]);
	data.time_to_eat = ft_atoi(v[3]);
	data.time_to_sleep = ft_atoi(v[4]);
	if (c == 6)
		data.number_of_t_eat = ft_atoi(v[5]);
	else
		data.number_of_t_eat = -1;
	data.forks = malloc(sizeof(pthread_mutex_t) * data.num_philosophers);
	data.wach_mat = 0;
	pthread_mutex_init(&data.lock_wach_mat, NULL);
	pthread_mutex_init(&data.print, NULL);
	return (data);
}

t_philo	*init_program(t_data *data, char **v, int c)
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
