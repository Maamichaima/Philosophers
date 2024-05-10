/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:06:48 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/07 21:56:05 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	main(int c, char **v)
{
	t_philo	*p;
	t_data	data;

	if (!check_args(c, v))
	{
		printf("invalide argument\n");
		return (0);
	}
	data = inisialiser_data(v, c);
	p = inisialiser(&data);
	create_process(&data, p);
	ft_free(p);
}
