/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:21:11 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/06 05:38:17 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	finish_simulation(pid_t *pid, t_philo *philo)
{
	int		err;
	int		i;

	i = 0;
	if (philo->info->must_eat != -1)
		philo->info->nbrp += 1;
	while (i < philo->info->nbrp)
	{
		waitpid(pid[i], &err, WUNTRACED);
		++i;
	}
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PICK_FORK);
	sem_unlink(SEM_DEATH);
	sem_unlink(SEM_MEALS);
	sem_unlink(SEM_WRITE);
}

int	main(int ac, char **av)
{
	t_philo	philo;
	t_info	info;
	pid_t	*pid;
	int		i;

	if (args_manager(ac, av, &info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philo.info = &info;
	if (init_philo(&philo, &pid) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_semaphores(&philo);
	i = 0;
	philo.info->start_time = get_current_time();
	print_action(&philo, MSG_START);
	while (i < philo.info->nbrp)
	{
		philo.id = i;
		pid[i] = fork();
		if (pid[i] == 0)
			init_routine(&philo);
		++i;
	}
	if (philo.info->must_eat != -1)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			check_meals_routine(&philo);
	}
	death_routine(pid, &philo);
	finish_simulation(pid, &philo);
	return (EXIT_SUCCESS);
}
