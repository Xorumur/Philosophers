/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:29:56 by mlecherb          #+#    #+#             */
/*   Updated: 2022/04/25 10:29:56 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void    free_struct(pthread_t *tab, pthread_mutex_t *mutex, t_data *d)
{
    int i;

    i = 0;
    free(tab);
    free(mutex);
    // while (i++ < d->rules->nb_philo - 1)
    //     free(&d.philo[i]);
    free(d->rules);
    free(d);
}

int checker_arg(char **argv)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (argv[i])
    {
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) != 1)
            {
                printf("Arguments must be numeric\n");
                return (0);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}

t_rules *init_rules(char **argv)
{
    t_rules *tmp;

    tmp = malloc(sizeof(t_rules));
    tmp->nb_philo = ft_atoi(argv[0]);
    tmp->time_to_die = ft_atoi(argv[1]);
    tmp->time_to_eat = ft_atoi(argv[2]);
    tmp->time_to_sleep = ft_atoi(argv[3]);
    if (argv[4])
        tmp->must_eat = ft_atoi(argv[4]);
    else
        tmp->must_eat = -1;
    return (tmp);
}

int main(int ac, char **argv)
{
    t_rules *rules;

    if (ac == 5 || ac == 6)
    {
        if (checker_arg(&argv[1]) != 1)
            return (0);
        rules = init_rules(&argv[1]);
        start_philo(rules);
    }
    else
    {
        printf("This program take at leat 5 or 6 arguments\n");
        return (0);
    }
    return (0);
}