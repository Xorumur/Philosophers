/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:33:57 by mlecherb          #+#    #+#             */
/*   Updated: 2022/04/25 10:33:57 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*init_philo(t_data *data, t_rules *rules, pthread_mutex_t *mutex)
{
	int			i;
	t_philo		*philo;
	
	philo = malloc(sizeof(t_philo) * rules->nb_philo);
	i = 0;
	while (i < rules->nb_philo)
	{
		philo[i].id = i + 1;
		pthread_mutex_init(&mutex[i], NULL);
		philo[i].index_philo = i;
		philo[i].isdead = 0;
		philo[i].rules = rules;
		philo[i].data = data;
		i++;
	}
	i = 0;
	while (i < rules->nb_philo)
	{
		if (i == 0)
			philo[i].left_fork = &mutex[rules->nb_philo - 1];
		else
			philo[i].left_fork = &mutex[i - 1];
		philo[i].right_fork = &mutex[i];
		i++;
	}
	return (philo);
}

void	launch_philo(t_rules *rules, t_data * d, pthread_t *tab, pthread_t *isdead)
{
	int	i;
	
	i = 0;
	while (i < rules->nb_philo)
	{
		if (i % 2 == 0)
		{
			pthread_create(&tab[i], NULL, &philo, &(d->philo[i]));
			usleep(50);
			pthread_create(&isdead[i], NULL, &philo_dead, &d->philo[i]);
		}
		i++;
	}
	usleep(100);
	i = 0;
	while (i < rules->nb_philo)
	{
		if ((i % 2 != 0))
		{
			pthread_create(&tab[i], NULL, &philo, &(d->philo[i]));
			usleep(50);
			pthread_create(&isdead[i], NULL, &philo_dead, &d->philo[i]);
		}
		i++;
	}
}

void	start_philo(t_rules *rules)
{
	pthread_t		*tab;
	int				i;
	pthread_mutex_t	*mutex;
	t_data			*data;
	pthread_t		*isdead;

	i = 0;
	tab = malloc(sizeof(pthread_t) * rules->nb_philo);
	isdead = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
	mutex = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
	data = malloc(sizeof(t_data));
	data->philo = init_philo(data, rules, mutex);
	pthread_mutex_init(&data->aff, NULL);
	data->rules = rules;
	data->time_today = get_current_time();
	pthread_mutex_init(&data->isdead, NULL);
	pthread_mutex_lock(&data->isdead);
	launch_philo(rules, data, tab, isdead);
	pthread_mutex_lock(&data->isdead);
	pthread_mutex_unlock(&data->isdead);
	free_struct(tab, mutex, data);
}