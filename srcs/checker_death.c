#include "../includes/philo.h"

void    *checker_death(t_data *d)
{
    while (1)
    {
        while (i < d->rules->nb_philo - 1)
        {
            if (d->philo[i]->isdead == 1)
            {
                pthread_mutex_unlock(&data->dead);
                return ((void*)0);
            }
            else
                i++;
        }
        i = 0;
    }
    return ((void*)0);
}