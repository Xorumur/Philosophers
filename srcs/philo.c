/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:06:47 by mlecherb          #+#    #+#             */
/*   Updated: 2022/05/14 19:59:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_fork(t_philo *philo)
{	
	pthread_mutex_lock(philo->left_fork);
	write_message_lock(1, (get_current_time() - philo->data->time_today),
		philo->id, philo);
	pthread_mutex_lock(philo->right_fork);
	write_message_lock(1, (get_current_time() - philo->data->time_today),
		philo->id, philo);
}

void	ft_eat(t_philo *philo)
{
	philo->eating = 1;
	write_message_lock(2, (get_current_time() - philo->data->time_today),
		philo->id, philo);
	philo->die_time = get_current_time();
	usleep(philo->rules->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->eating = 0;
}

void	ft_sleep(t_philo *philo)
{
	write_message_lock(3, (get_current_time() - philo->data->time_today),
		philo->id, philo);
	usleep(philo->rules->time_to_sleep * 1000);
	write_message_lock(4, (get_current_time() - philo->data->time_today),
		philo->id, philo);
}

void	*philo(void *phil)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)phil;
	philo->die_time = get_current_time();
	while (1)
	{
		ft_fork(philo);
		ft_eat(philo);
		i++;
		if (philo->rules->must_eat != -1 && i == philo->rules->must_eat)
		{
			philo->isdead = 1;
			break ;
		}
		ft_sleep(philo);
	}
	return ((void *)0);
}
