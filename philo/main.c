/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:01:14 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/06 13:59:14 by cmaami           ###   ########.fr       */
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

void	join_and_destroy(t_philo *p, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_join(p[i].id, NULL);
		i++;
	}
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&p[i].mutex_compt_n_o_t_eat);
		pthread_mutex_destroy(&p[i].mutex_last_time_eat);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->lock_is_died);
}

int	main(int c, char **v)
{
	t_philo	*p;
	t_data	data;

	if (!check_args(c, v))
	{
		printf("invalide argument\n");
		return (0);
	}
	p = init_program(&data, v, c);
	if (data.number_of_t_eat == 0 || data.num_philosophers == 0)
	{
		return (0);
	}
	if (create_threads(p, data))
	{
		ft_free(p);
		return (0);
	}
	join_and_destroy(p, &data);
	ft_free(p);
	return (0);
}
