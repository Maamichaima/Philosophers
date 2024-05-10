/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:22:46 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/07 21:58:34 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	check_someone_died(t_philo *philo)
{
	size_t	time_stamp;

	time_stamp = get_current_time() - ((philo->data->last_time_eat.tv_sec
				* 1000) + (philo->data->last_time_eat.tv_usec / 1000));
	if (time_stamp >= philo->data->time_to_die)
		return (1);
	return (0);
}

int	check_args(int c, char **v)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	v++;
	if (c == 5 || c == 6)
	{
		while (i < c - 1)
		{
			num = ft_atoi(v[i]);
			if (num <= 0 || num >= 2147483647)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
