/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:12:34 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/22 05:25:52 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eat_routine(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_lock(&(philo->info->forks[philo->id]));
		pthread_mutex_lock(&(philo->info->forks[philo->id + 1]));
	}
	else if ((philo->id % 2) == 1)
	{
		pthread_mutex_lock(&(philo->info->forks[philo->id + 1]));
		pthread_mutex_lock(&(philo->info->forks[philo->id]));
	}
	print_action_time(philo->id, MSG_FORK);
	print_action_time(philo->id, MSG_FORK);
	print_action_time(philo->id, MSG_EAT);
	wait_given_time(philo->info->time_eat);
	philo->last_meal = get_current_time();
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_unlock(&(philo->info->forks[philo->id]));
		pthread_mutex_unlock(&(philo->info->forks[philo->id + 1]));
	}
	else if ((philo->id % 2) == 1)
	{
		pthread_mutex_unlock(&(philo->info->forks[philo->id + 1]));
		pthread_mutex_unlock(&(philo->info->forks[philo->id]));
	}
	sleep_routine(philo);
	return (NULL);
}
