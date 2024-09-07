/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <jmiguel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:10:25 by jmiguel           #+#    #+#             */
/*   Updated: 2024/09/06 09:19:16 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	long	last_meal_time;

	philo = (t_philo *)arg;
	philo->start_time = get_time();
	last_meal_time = get_time();
	while (1)
	{
		print_status(philo, "is thinking...");
		if (philo->number_of_philosophers == 1)
		{
			pthread_mutex_lock(philo->left_fork);
			print_status(philo, "has taken a left fork...");
			usleep(philo->time_to_die * 1000);
			print_status(philo, "died");
			break ;
		}
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->right_fork);
			print_status(philo, "has taken a right fork...");
			pthread_mutex_lock(philo->left_fork);
			print_status(philo, "has taken a left fork...");
		}
		else
		{
			pthread_mutex_lock(philo->left_fork);
			print_status(philo, "has taken a left fork...");
			pthread_mutex_lock(philo->right_fork);
			print_status(philo, "has taken a right fork...");
		}
		print_status(philo, "is eating...");
		usleep(philo->time_to_eat * 1000);
		philo->meals_count++;
		last_meal_time = get_time();
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		print_status(philo, "is sleeping...");
		usleep(philo->time_to_sleep * 1000);
		if (get_time() - last_meal_time > philo->time_to_die)
		{
			print_status(philo, "died");
			break ;
		}
	}
	return (NULL);
}

void	philo_table(int number_of_philosophers, int time_to_die,
		int time_to_eat, int time_to_sleep, int max_meals)
{
	int				i;
	t_philo			philosoph[number_of_philosophers];
	pthread_mutex_t	forks[number_of_philosophers];
	pthread_t		threads[number_of_philosophers];

	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		philosoph[i].id = i + 1;
		philosoph[i].left_fork = &forks[i];
		philosoph[i].right_fork = &forks[(i + 1) % number_of_philosophers];
		philosoph[i].time_to_die = time_to_die;
		philosoph[i].time_to_sleep = time_to_sleep;
		philosoph[i].time_to_eat = time_to_eat;
		philosoph[i].meals_count = 0;
		philosoph[i].max_meals = max_meals;
		philosoph[i].number_of_philosophers = 0;
		philosoph[i].number_of_philosophers = number_of_philosophers;
		philosoph[i].start_time = get_time();
		i++;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_create(&threads[i], NULL, philo_routine, &philosoph[i]);
		i++;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}