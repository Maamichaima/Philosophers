/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:43:46 by cmaami            #+#    #+#             */
/*   Updated: 2024/04/25 18:45:46 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

void	is_sleeping(t_philo *philo)
{
	// if(philo->data->wach_mat == 0)
	// {
	print('s', *philo);
	ft_usleep(philo->data->time_to_sleep, *(philo->data));
	// }
}
