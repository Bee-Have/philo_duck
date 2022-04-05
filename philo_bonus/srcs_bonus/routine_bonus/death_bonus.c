/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:14:48 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/04 23:55:05 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_meals_routine(t_philo *philo)
{
	int	count;

	count = 0;
	while (1)
	{
		sem_wait(philo->sem_meals);
		++count;
		if (count == philo->info->nbrp)
			sem_post(philo->sem_death);
	}
}

void	death_routine(pid_t *pid, t_philo *philo)
{
	int	i;

	sem_wait(philo->sem_death);
	i = 0;
	if (philo->info->must_eat != -1)
		philo->info->nbrp += 1;
	while (i < philo->info->nbrp)
	{
		kill(pid[i], SIGQUIT);
		++i;
	}
}
