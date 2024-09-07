/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <jmiguel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:10:26 by jmiguel           #+#    #+#             */
/*   Updated: 2024/09/06 08:56:57 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philosoph
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				id;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				meals_count;
	int				max_meals;
	int				number_of_philosophers;
	long			start_time;
	int				number_of_time_to_eat;
}					t_philo;

// utils
int					ft_atoi(char *str);
int					ft_isdigit(int c);

// time
long				get_time(void);
void				print_status(t_philo *philo, const char *status);

// verificacao
int					verif_args(char **argv);
int					philosophers_verifs(int number_of_philosophers,
						int time_to_die, int time_to_eat, int time_to_sleep);

// table
void				*philo_routine(void *arg);
void				philo_table(int number_of_philosophers, int time_to_die,
						int time_to_eat, int time_to_sleep, int max_meals);
int					check_philo_death_or_meals(t_philo *philos,
						int number_of_philosophers);
#endif

// Vermelho Escuro: \033[0;31m \033[0m\n
// Vermelho Claro: \033[1;31m \033[0m\n
// Verde Escuro: \033[0;32m \033[0m\n
// Verde Claro: \033[1;32m \033[0m\n
// Azul escuro: \033[0;34m \033[0m\n
// Azul claro: \033[1;34m \033[0m\n
