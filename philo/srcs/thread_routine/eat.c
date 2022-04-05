/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:12:34 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/05 19:38:43 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eat_routine(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	if (philo_check_death(philo->info) == EXIT_FAILURE)
		return (NULL);
	if (lock_fork_mutex(philo) == EXIT_FAILURE)
		return (NULL);
	if (print_meal_actions(philo) == EXIT_FAILURE)
	{
		unlock_fork_mutex(philo);
		return (NULL);
	}
	if (wait_time(philo->info->time_eat, philo->info) == EXIT_FAILURE)
	{
		unlock_fork_mutex(philo);
		return (NULL);
	}
	unlock_fork_mutex(philo);
	pthread_mutex_lock(&philo->meals_n);
	++philo->meals_nbr;
	pthread_mutex_unlock(&philo->meals_n);
	if (philo_check_death(philo->info) == EXIT_FAILURE)
		return (NULL);
	sleep_routine(philo);
	return (NULL);
}

int	print_meal_actions(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal);
	if (print_action(philo->info, philo->id, MSG_EAT) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	lock_fork_mutex(t_philo *philo)
{
	int	index;

	if ((philo->id % 2) == 0)
	{
		pthread_mutex_lock(&(philo->info->forks[philo->id]));
		if (print_action(philo->info, philo->id, MSG_FORK_ON) == EXIT_FAILURE)
		{
			pthread_mutex_unlock(&(philo->info->forks[philo->id]));
			return (EXIT_FAILURE);
		}
		if (philo->id == philo->info->nbrp - 1)
			index = 0;
		else
			index = philo->id + 1;
		pthread_mutex_lock(&(philo->info->forks[index]));
		if (print_action(philo->info, philo->id, MSG_FORK_ON) == EXIT_FAILURE)
		{
			pthread_mutex_unlock(&(philo->info->forks[index]));
			pthread_mutex_unlock(&(philo->info->forks[philo->id]));
			return (EXIT_FAILURE);
		}
	}
	else
	{
		if (philo->id == philo->info->nbrp - 1)
			index = 0;
		else
			index = philo->id + 1;
		pthread_mutex_lock(&(philo->info->forks[index]));
		if (print_action(philo->info, philo->id, MSG_FORK_ON) == EXIT_FAILURE)
		{
			pthread_mutex_unlock(&(philo->info->forks[index]));
			return (EXIT_FAILURE);
		}
		pthread_mutex_lock(&(philo->info->forks[philo->id]));
		if (print_action(philo->info, philo->id, MSG_FORK_ON) == EXIT_FAILURE)
		{
			pthread_mutex_unlock(&(philo->info->forks[index]));
			pthread_mutex_unlock(&(philo->info->forks[philo->id]));
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
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
