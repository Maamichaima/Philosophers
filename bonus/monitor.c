/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:55:46 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/07 14:27:45 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int w9ef(t_philo *philosopher)
{
	int i;
	
	i = 0;
	while(i < philosopher[0].data->num_philosophers)
	{
		if(check_last_time_eat(&philosopher[i]))
			return 0;
		i++;
	}
	return 1;
}
int	corpse_check(t_data *data)
{
	int	b;

	sem_wait(data->lock_wach_mat);
	b = (data->wach_mat == 1);
	sem_post(data->lock_wach_mat);
	return (b);
}
void	*monitor(void *data)
{
	int	i;

	i = 0;
	t_philo *philosopher;
	philosopher = (t_philo *) data;
	while (check_last_time_eat(philosopher))
		usleep(500);
	while (!corpse_check((philosopher[0].data)))
	{
		if (check_someone_died(&philosopher[i]) == 1 && !safi_chbe3o(philosopher))
		{
			print('d', &philosopher[i]);
			exit(1);
		}
		i = 0;
	}
	return (NULL);
}
