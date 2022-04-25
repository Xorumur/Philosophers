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

void    *checker_death(void *data)
{
	t_data	*d;
	int	i;

	d = (t_data *)data;
	i = 0;
    while (1)
    {
        while (i < d->rules->nb_philo - 1)
        {
            if (d->philo[i].isdead == 1)
            {
                pthread_mutex_unlock(&d->dead);
                return ((void*)0);
            }
            else
                i++;
        }
        i = 0;
    }
    return ((void*)0);
}