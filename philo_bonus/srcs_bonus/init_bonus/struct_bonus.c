/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 06:09:06 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/06 06:12:17 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_info(int ac, char **av, t_info *info)
{
	info->nbrp = am_atol(av[1]);
	info->time_die = am_atol(av[2]);
	info->time_eat = am_atol(av[3]);
	info->time_sleep = am_atol(av[4]);
	if (ac == 6)
	{
		info->must_eat = am_atol(av[5]);
		if (info->must_eat <= 0 || info->must_eat > INT_MAX)
			return (EXIT_FAILURE);
	}
	else
		info->must_eat = -1;
	return (EXIT_SUCCESS);
}

int	init_philo(t_philo *philo, pid_t **pid)
{
	philo->id = 0;
	philo->dead = 0;
	philo->meals_nbr = 0;
	philo->last_meal = 0;
	if (philo->info->must_eat != -1)
		*pid = (pid_t *)malloc((philo->info->nbrp + 1) * sizeof(pid_t));
	else
		*pid = (pid_t *)malloc(philo->info->nbrp * sizeof(pid_t));
	if (!*pid)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	init_semaphores(t_philo *philo)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PICK_FORK);
	sem_unlink(SEM_DEATH);
	sem_unlink(SEM_MEALS);
	sem_unlink(SEM_WRITE);
	philo->sem_forks = sem_open(SEM_FORKS, O_CREAT, 0777, philo->info->nbrp);
	philo->sem_pick_fork = sem_open(SEM_PICK_FORK, O_CREAT, 0777, 1);
	philo->sem_meals = sem_open(SEM_MEALS, O_CREAT, 0777, 0);
	philo->sem_death = sem_open(SEM_DEATH, O_CREAT, 0777, 0);
	philo->sem_write = sem_open(SEM_WRITE, O_CREAT, 0777, 1);
}
