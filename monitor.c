/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:55:46 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/02 19:52:00 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

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

void	monitor(t_philo *philosopher)
{
	int	i;

	i = 0;
	while(!w9ef(philosopher))
		usleep(500);
	while (!corpse_check((philosopher[0].data)))//!safi_chbe3o(philosopher) && 
	{
		while (i < philosopher[0].data->num_philosophers)
		{
			if (check_someone_died(&philosopher[i]) == 1 && !safi_chbe3o(philosopher))
			{
				print('d', &philosopher[i]);
				i = 0;
				break ;
			}
			i++;
		}
		i = 0;
	}
}
