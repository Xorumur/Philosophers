#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct  s_rules 
{
    int nb_philo;
    int time_to_eat;
    int time_to_sleep;
    int time_to_die;
    int must_eat;
}   t_rules;

typedef struct s_philo
{
    pthread_mutex_t left_fork;
    pthread_mutex_t right_fork;
    int             isdead;
    int index_philo;
}   t_philo;

typedef struct s_data
{
    t_philo *philo;
    t_rules *rules;
    pthread_mutex_t dead;
}   t_data;

void    start_philo(t_rules *rules);
void    *routine(void);
void    free_struct(pthread_t *tab, pthread_mutex_t *mutex, t_data *d);


#endif