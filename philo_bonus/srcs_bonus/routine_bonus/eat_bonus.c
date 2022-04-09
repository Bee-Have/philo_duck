/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:11:50 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/09 05:07:12 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	pick_up_forks(t_philo *philo)
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
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal);
	if (print_action(philo, MSG_EAT) == EXIT_FAILURE)
	{
		sem_post(philo->sem_forks);
		sem_post(philo->sem_forks);
		exit (EXIT_FAILURE);
	}
}

void	eat_routine(t_philo *philo)
{
	if (check_death(philo) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	pick_up_forks(philo);
	eat(philo);
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
	if (check_death(philo) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	sleep_routine(philo);
}
