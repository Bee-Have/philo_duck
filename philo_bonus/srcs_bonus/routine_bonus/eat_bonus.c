/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:11:50 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/04 18:54:39 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat_routine(t_philo *philo)
{
	sem_wait(philo->sem_pick_fork);
	sem_wait(philo->sem_forks);
	if (print_action(philo, MSG_FORK_ON) == EXIT_FAILURE)
	{
		sem_post(philo->sem_forks);
		exit (EXIT_FAILURE);
	}
	sem_wait(philo->sem_forks);
	if (print_action(philo, MSG_FORK_ON) == EXIT_FAILURE)
	{
		sem_post(philo->sem_forks);
		sem_post(philo->sem_forks);
		exit (EXIT_FAILURE);
	}
	sem_post(philo->sem_pick_fork);
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal);
	if (print_action(philo, MSG_EAT) == EXIT_FAILURE)
	{
		sem_post(philo->sem_forks);
		sem_post(philo->sem_forks);
		exit (EXIT_FAILURE);
	}
	if (wait_time(philo->info->time_eat, philo) == EXIT_FAILURE)
	{
		sem_post(philo->sem_forks);
		sem_post(philo->sem_forks);
		exit (EXIT_FAILURE);
	}
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
	pthread_mutex_lock(&philo->meals_n);
	philo->meals_nbr += 1;
	pthread_mutex_unlock(&philo->meals_n);
	sleep_routine(philo);
}
