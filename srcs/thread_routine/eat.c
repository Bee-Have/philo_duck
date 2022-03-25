/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:12:34 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/25 15:33:45 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eat_routine(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	// pthread_mutex_lock(&philo->info->death);
	if (philo->info->dead == 1)
		return (NULL);
	// pthread_mutex_unlock(&philo->info->death);
	pthread_mutex_lock(&philo->meal);
	if (philo->last_meal == 0)
		philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal);
	lock_fork_mutex(philo);
	if (print_action(philo->info, philo->id, MSG_FORK) == EXIT_FAILURE)
	{
		unlock_fork_mutex(philo);
		return (NULL);
	}
	if (print_action(philo->info, philo->id, MSG_FORK) == EXIT_FAILURE)
	{
		unlock_fork_mutex(philo);
		return (NULL);
	}
	if (print_action(philo->info, philo->id, MSG_EAT) == EXIT_FAILURE)
	{
		unlock_fork_mutex(philo);
		return (NULL);
	}
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal);
	if (wait_time(philo->info->time_eat, philo->info) == EXIT_FAILURE)
	{
		unlock_fork_mutex(philo);
		return (NULL);
	}
	unlock_fork_mutex(philo);
	// pthread_mutex_lock(&philo->info->death);
	if (philo->info->dead == 1)
		return (NULL);
	// pthread_mutex_unlock(&philo->info->death);
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
