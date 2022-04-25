#include "../includes/philo.h"

void    *routine(void)
{
    // mutex = (pthread_mutex_t *)mutex;
    printf("Hello\n");
    
    return ((void*)0);
}


void    start_philo(t_rules *rules)
{
    pthread_t *tab;
    int i;
    pthread_mutex_t *mutex;
    t_philo         *philo;
    t_data          *data;
    phtread_t checker;

    i = 0;
    tab = malloc(sizeof(unsigned long int) * rules->nb_philo);
    mutex = malloc(sizeof(unsigned long int) * rules->nb_philo);
    philo = malloc(sizeof(t_philo) * rules->nb_philo);
    data = malloc(sizeof(t_data));
    while (i++ < rules->nb_philo)
        pthread_mutex_init(&mutex[i], NULL);
    i = 0;
    while (i < rules->nb_philo)
    {
        if (i == 0)
            philo[i].left_fork = mutex[rules->nb_philo - 1];
        else
            philo[i].left_fork = mutex[i - 1];
        philo[i].right_fork = mutex[i];
        philo[i].index_philo = i;
        philo[i].isdead = 0;
        i++;
    }
    data->philo = philo;
    data->rules = rules;
    while (i++ < rules->nb_philo)
        pthread_create(&tab[i], NULL, &routine, NULL);
    pthread_mutex_lock(&data->dead);
    pthread_create(checker, NULL, &checker_death(d), NULL);
    pthread_mutex_lock(&data->dead);
    pthread_mutex_unlock(&data->dead);
    free_struct(tab, mutex, d);
}