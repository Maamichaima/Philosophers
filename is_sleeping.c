/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:43:46 by cmaami            #+#    #+#             */
/*   Updated: 2024/04/28 15:50:54 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

void	is_sleeping(t_philo *philo)
{
	print('s', *philo);
	ft_usleep(philo->data->time_to_sleep, *(philo->data));
}
