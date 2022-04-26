/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:03:09 by mlecherb          #+#    #+#             */
/*   Updated: 2022/04/26 10:27:04 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_message_lock(int msg, unsigned long long time,
								int id, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->aff);
	if (msg == 1)
		printf("%llu\t%i has taken a fork\n", time, id);
	else if (msg == 2)
		printf("%llu\t%i is eating\n", time, id);
	else if (msg == 3)
		printf("%llu\t%i is sleeping\n", time, id);
	else if (msg == 4)
		printf("%llu\t%i is thinking\n", time, id);
	else if (msg == 5)
		printf("%llu\t%i died\n", time, id);
	else if (msg == 6)
		printf("Each philosophers ate %i times\n", philo->rules->must_eat);
	if ((msg != 5 && msg != 6))
		pthread_mutex_unlock(&philo->data->aff);
}
