/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:50:20 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/07 21:57:16 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	inisialiser_data(t_data *data, char **v, int c)
{
	data->num_philosophers = ft_atoi(v[1]);
	data->time_to_die = ft_atoi(v[2]);
	data->time_to_eat = ft_atoi(v[3]);
	data->time_to_sleep = ft_atoi(v[4]);
	if (c == 6)
		data->number_of_t_eat = ft_atoi(v[5]);
	else
		data->number_of_t_eat = -1;
	if (data->num_philosophers == 0 || data->number_of_t_eat == 0)
		return (0);
	sem_unlink("print");
	sem_unlink("sem_last_time_eat");
	sem_unlink("forks");
	data->pids = malloc(sizeof(pid_t) * data->num_philosophers);
	data->forks = sem_open("forks", O_CREAT, 0666, data->num_philosophers);
	data->print = sem_open("print", O_CREAT, 0666, 1);
	data->sem_last_time_eat = sem_open("sem_last_time_eat", O_CREAT, 0666, 1);
	return (1);
}

t_philo	*inisialiser(t_data *data)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(t_philo) * data->num_philosophers);
	if (!p)
		return (NULL);
	while (i < data->num_philosophers)
	{
		p[i].data = data;
		p[i].index = i + 1;
		p[i].compt_n_o_t_eat = 0;
		gettimeofday(&data->last_time_eat, NULL);
		i++;
	}
	return (p);
}

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
