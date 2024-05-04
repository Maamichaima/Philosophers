/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:40:31 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/03 10:40:37 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

void	ft_free(t_philo *philosopher)
{
	if (philosopher != NULL)
	{
		free(philosopher->data->forks);
		free(philosopher);
	}
}
