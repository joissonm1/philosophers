/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <jmiguel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:19:57 by jmiguel           #+#    #+#             */
/*   Updated: 2024/09/07 10:24:23 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philo *philosoph, pthread_t *threads, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_create(&threads[i], NULL, philo_routine, &philosoph[i]);
		i++;
	}
}

void	join_threads(pthread_t *threads, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	destroy_mutexes(pthread_mutex_t *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
