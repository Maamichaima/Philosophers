/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:00:17 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/04 15:00:53 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

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
