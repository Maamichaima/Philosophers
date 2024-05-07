/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:06:48 by cmaami            #+#    #+#             */
/*   Updated: 2024/05/07 14:32:23 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosopher_bonus.h"

int	ft_atoi(char *str)
{
	long	nb;
	int		i;
	int		signe;

	i = 0;
	nb = 0;
	signe = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10;
		nb += str[i] - '0';
		i++;
	}
	return (signe * nb);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t milliseconds, t_data *data)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds && !corpse_check(data))
		usleep(500);
}

void join_and_destroy(t_philo *p, t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_join(p[i].id, NULL);
		i++;
	}
}
void	is_sleeping(t_philo *philo)
{
	print('s', philo);
	ft_usleep(philo->data->time_to_sleep, (philo->data));
}
void	is_thinking(t_philo *philo)
{
	print('t', philo);
}

void	thread_routine(t_philo *philosopher)
{
	sem_wait(philosopher->mutex_last_time_eat);
	philosopher->last_time_eat = get_current_time();
	sem_post(philosopher->mutex_last_time_eat);
	if (philosopher->index % 2 == 0)
		ft_usleep(60, (philosopher->data));
	while (!corpse_check(philosopher->data) && was_not_satisfied(*philosopher))
	{
		is_eating(philosopher);
		is_sleeping(philosopher);
		is_thinking(philosopher);
	}
}

void kill_all(t_data *data)
{
	int i;
	
	i = 0;
	while(i < data->num_philosophers)
	{
		kill(data->pids[i], SIGKILL);
		i++;
	}
}

void create_process(t_data *data, t_philo *philo)
{
    int i;
	int status;

    i = 0;
	philo->data->daba = get_current_time();
    while(i < data->num_philosophers)
    {
        data->pids[i] = fork();
        if(data->pids[i] == 0)
        {
			pthread_create(&philo[i].id, NULL, monitor, &philo[i]);
			thread_routine(&philo[i]);
			pthread_join(philo[i].id, NULL);
            exit(0);
        }
        i++;
    }
	i = 0;
	while (i < data->num_philosophers)
	{
		waitpid(-1, &status, 0);
		if(status != 0)// status)//(
			kill_all(data);
		i++;
	}
}

int main(int c, char **v)
{
    t_philo *p;
    t_data data;

    if (!check_args(c, v))
	{
		printf("invalide argument\n");
		return (0);
	}
	sem_unlink("lock_wach_mat");
	sem_unlink("print");
	sem_unlink("mutex_last_time_eat");
	sem_unlink("forks");
    data = inisialiser_data(v, c);
    p = inisialiser(&data);
    create_process(&data, p);
}
