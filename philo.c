/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <jmiguel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:12:34 by jmiguel           #+#    #+#             */
/*   Updated: 2024/09/06 13:34:23 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo	philo;

	philo.max_meals = -1;
	if (argc != 5 && argc != 6)
	{
		printf("\033[1;31mNúmero inválido de argumentos!\033[0m\n");
		return (1);
	}
	if (verif_args(argv))
		return (1);
	philo.number_of_philosophers = ft_atoi(argv[1]);
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo.max_meals = atoi(argv[5]);
	philo_table(philo.number_of_philosophers, philo.time_to_die,
		philo.time_to_eat, philo.time_to_sleep, philo.max_meals);
	return (0);
}
