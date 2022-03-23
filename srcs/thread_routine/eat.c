/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:12:34 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/23 17:03:09 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eat_routine(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	lock_fork_mutex(philo);
	print_action_time(philo->id, MSG_FORK);
	print_action_time(philo->id, MSG_FORK);
	print_action_time(philo->id, MSG_EAT);
	wait_given_time(philo->info->time_eat);
	philo->last_meal = get_current_time();
	unlock_fork_mutex(philo);
	sleep_routine(philo);
	return (NULL);
}

void	lock_fork_mutex(t_philo *philo)
{
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_lock(&(philo->info->forks[philo->id]));
		if (philo->id == philo->info->nbrp - 1)
			pthread_mutex_lock(&(philo->info->forks[0]));
		else
			pthread_mutex_lock(&(philo->info->forks[philo->id + 1]));
	}
	else
	{
		if (philo->id == philo->info->nbrp - 1)
			pthread_mutex_lock(&(philo->info->forks[0]));
		else
			pthread_mutex_lock(&(philo->info->forks[philo->id + 1]));
		pthread_mutex_lock(&(philo->info->forks[philo->id]));
	}
}

void	unlock_fork_mutex(t_philo *philo)
{
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_unlock(&(philo->info->forks[philo->id]));
		if (philo->id == philo->info->nbrp - 1)
			pthread_mutex_unlock(&(philo->info->forks[0]));
		else
			pthread_mutex_unlock(&(philo->info->forks[philo->id + 1]));
	}
	else
	{
		if (philo->id == philo->info->nbrp - 1)
			pthread_mutex_unlock(&(philo->info->forks[0]));
		else
			pthread_mutex_unlock(&(philo->info->forks[philo->id + 1]));
		pthread_mutex_unlock(&(philo->info->forks[philo->id]));
	}
}
