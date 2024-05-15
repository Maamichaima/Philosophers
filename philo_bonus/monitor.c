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

void	*monitor(void *data)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)data;
	while (1)
	{
		if (check_someone_died(philosopher) == 1)
		{
			print('d', philosopher);
			ft_free(philosopher);
			exit(1);
		}
		usleep(500);
	}
	return (NULL);
}
