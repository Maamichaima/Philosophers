/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:50:20 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/07 12:31:35 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

t_data	inisialiser_data(char **v, int c)
{
	t_data	data;

	data.num_philosophers = ft_atoi(v[1]);
	data.time_to_die = ft_atoi(v[2]);
	data.time_to_eat = ft_atoi(v[3]);
	data.time_to_sleep = ft_atoi(v[4]);
	if (c == 6)
		data.number_of_times_each_philosopher_must_eat = ft_atoi(v[5]);
	else
		data.number_of_times_each_philosopher_must_eat = -1;
	data.pids = malloc(sizeof(pid_t) * data.num_philosophers);
    data.wach_mat = 0;
	data.lock_wach_mat = sem_open("lock_wach_mat", O_CREAT, 0644, 1);
	data.forks = sem_open("forks", O_CREAT, 0666, data.num_philosophers);
	data.print = sem_open("print", O_CREAT, 0666, 1);
	return (data);
}

t_philo *inisialiser(t_data *data)
{
    t_philo *p;
    int i;

    i = 0;
    p = malloc(sizeof(t_philo) * data->num_philosophers);
    if(!p)
        return NULL;
    while(i < data->num_philosophers)
    {
        p[i].data = data;
		p[i].index = i + 1;
		p[i].mutex_last_time_eat = sem_open("mutex_last_time_eat", O_CREAT, 0666, 1);
        p[i].compt_n_o_t_eat = 0;
		p[i].last_time_eat = 0;
        i++;
    }
    return p;
}

t_philo	*init_program(t_data *data, char **v, int c)
{
	t_philo	*p;
	int		i;

	i = 0;
	*data = inisialiser_data(v, c);
	p = inisialiser(data);
	return (p);
}
