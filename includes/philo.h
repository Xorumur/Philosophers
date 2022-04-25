/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:06:09 by mlecherb          #+#    #+#             */
/*   Updated: 2022/04/25 11:06:09 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <sys/time.h>

typedef struct	s_rules 
{
	int	nb_philo;
	int	time_to_eat;
	int	time_to_sleep;
	unsigned long long int	time_to_die;
	int	must_eat;
}	t_rules;

typedef struct	s_philo t_philo;
typedef struct	s_data t_data;

typedef struct	s_data
{
	t_philo 		*philo;
	t_rules 		*rules;
	pthread_mutex_t	isdead;
	pthread_mutex_t	aff;
	int				time_today;
}	t_data;

typedef struct	s_philo
{
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	int					isdead;
	int					index_philo;
	int					eating;
	unsigned long long	die_time;
	int					id;
	t_rules				*rules;
	struct s_data		*data;
}	t_philo;


void	start_philo(t_rules *rules);
void	*routine(void);
void	free_struct(pthread_t *tab, pthread_mutex_t *mutex, t_data *d);
void	*checker_death(void *data);
void	*philo(void *data);
void	write_message_lock(int msg, unsigned long long time,
							int id, t_philo *philo);
unsigned long long	get_current_time(void);
void	launch_philo(t_rules *rules, t_data * d, pthread_t *tab, pthread_t *isdead);
void	*philo_dead(void *phil);

#endif