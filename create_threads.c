/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:07:34 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/03 14:07:40 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

int	create_threads(t_philo *p, t_data data)
{
	int	i;

	if (data.num_philosophers == 1)
	{
		pthread_create(&(p->id), NULL, routine_one_philo, &(p[0]));
		pthread_join((p->id), NULL);
		pthread_mutex_destroy(p->right);
		return (1);
	}
	else
	{
		i = 0;
		p->data->daba = get_current_time();
		while (i < data.num_philosophers)
		{
			pthread_create(&(p[i].id), NULL, thread_routine, &(p[i]));
			i++;
		}
		monitor(p);
		return (0);
	}
}
