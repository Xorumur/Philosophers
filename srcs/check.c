/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:30:04 by mlecherb          #+#    #+#             */
/*   Updated: 2022/04/25 10:30:04 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_dead(void *phil)
{
	t_philo				*philo;

	philo = (t_philo *)phil;
	while (1)
	{
		if ((philo->eating == 0 && get_current_time() - \
			philo->die_time >= philo->rules->time_to_die) || philo->isdead == 1)
		{
			if (philo->isdead == 1)
			{
				pthread_mutex_unlock(&philo->data->isdead);
				write_message_lock(6, (get_current_time() \
					- philo->data->time_today), philo->id, philo);
				break ;
			}
			write_message_lock(5, (get_current_time() - \
						philo->data->time_today), philo->id, philo);
			pthread_mutex_unlock(&philo->data->isdead);
			return (NULL);
		}
		usleep(2000);
	}
	return (NULL);
}
