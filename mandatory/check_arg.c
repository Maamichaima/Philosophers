/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:31:34 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/14 18:31:38 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pphilo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_int(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] && (argv[i] == '+' || argv[i] == '-'))
		i++;
	if (!argv[i])
		return (0);
	while (argv[i] && argv[i] == '0')
		i++;
	if (ft_strlen(argv + i) > 11)
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
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
			if (!is_int(v[i]))
				return (0);
			num = ft_atoi(v[i]);
			if (num < 0 || num >= 2147483647)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
