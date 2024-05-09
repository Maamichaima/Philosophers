/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:55:46 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/07 21:36:36 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

// int	w9ef(t_philo *philosopher)
// {
// 	int	i;

// 	i = 0;
// 	while (i < philosopher[0].data->num_philosophers)
// 	{
// 		if (check_last_time_eat(&philosopher[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	corpse_check(t_data *data)
// {
// 	int	b;

// 	sem_wait(data->lock_wach_mat);
// 	b = (data->wach_mat == 1);
// 	sem_post(data->lock_wach_mat);
// 	return (b);
// }

void	*monitor(void *data)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)data;
	while (1)
	{
		if (check_someone_died(philosopher) == 1)
		{
			print('d', philosopher);
			exit(1);
		}
		usleep(500);
	}
	return (NULL);
}
