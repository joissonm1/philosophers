/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <jmiguel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:06:46 by jmiguel           #+#    #+#             */
/*   Updated: 2024/09/06 08:57:45 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("\033[1;31mInválido!\033[0m\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	philosophers_verifs(int number_of_philosophers, int time_to_die,
		int time_to_eat, int time_to_sleep)
{
	if (number_of_philosophers < 1)
	{
		printf("\033[1;31mNúmero de filósofos inválido!\033[0m\n");
		return (0);
	}
	if (time_to_sleep < 1 || time_to_die < 1 || time_to_eat < 1)
	{
		printf("\033[1;31mTempo inválido!\033[0m\n");
		return (0);
	}
	return (1);
}

long	get_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	print_status(t_philo *philo, const char *status)
{
	long	time;

	time = get_time() - philo->start_time;
	printf("\033[0;36m[TIME = %ldms] - %d\033[0m %s\n", time, philo->id,
		status);
}
