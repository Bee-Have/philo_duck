/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vitals_routine_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:55:13 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/01 00:05:22 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_vitals(void *human)
{
	t_philo	*philo;
	t_info	*all_info;
	long	elapsed;

	printf("test checking vitals\n");
	philo = (t_philo *)human;
	all_info = philo->info;
	while (1)
	{
		//check last_meal
		pthread_mutex_lock(&philo->meal);
		if (philo->last_meal == 0)
			elapsed = 0;
		else
			elapsed = get_current_time() - philo->last_meal;
		pthread_mutex_unlock(&philo->meal);
		if (elapsed >= all_info->time_die)
		{
			print_action(philo, MSG_DIED);
			pthread_mutex_lock(&philo->death);
			philo->dead = 1;
			pthread_mutex_unlock(&philo->death);
			sem_post(philo->sem_death);
			return (NULL);
		}
	}
	return (NULL);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->death);
	if (philo->dead == 1)
	{
		pthread_mutex_unlock(&philo->death);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&philo->death);
	return (EXIT_SUCCESS);
}
