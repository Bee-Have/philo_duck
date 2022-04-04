/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:21:11 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/04 18:57:33 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	init_philo(t_philo *philo)
{
	philo->id = 0;
	philo->dead = 0;
	philo->meals_nbr = 0;
	philo->last_meal = 0;
}

int	main(int ac, char **av)
{
	t_philo	philo;
	t_info	info;
	pid_t	*pid;
	int		err;
	int		i;

	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PICK_FORK);
	sem_unlink(SEM_DEATH);
	sem_unlink(SEM_MEALS);
	if (args_manager(ac, av, &info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philo.info = &info;
	init_philo(&philo);
	philo.sem_forks = sem_open(SEM_FORKS, O_CREAT, 0777, philo.info->nbrp);
	philo.sem_pick_fork = sem_open(SEM_PICK_FORK, O_CREAT, 0777, 1);
	philo.sem_meals = sem_open(SEM_MEALS, O_CREAT, 0777, 0);
	philo.sem_death = sem_open(SEM_DEATH, O_CREAT, 0777, 0);
	if (philo.info->must_eat != -1)
		pid = (pid_t *)malloc((philo.info->nbrp + 1) * sizeof(pid_t));
	else
		pid = (pid_t *)malloc(philo.info->nbrp * sizeof(pid_t));
	if (!pid)
		return (EXIT_FAILURE);
	i = 0; 
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
	i = 0;
	death_routine(pid, &philo);
	if (philo.info->must_eat != -1)
		philo.info->nbrp += 1;
	while (i < philo.info->nbrp)
	{
		waitpid(pid[i], &err, WUNTRACED);
		++i;
	}
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PICK_FORK);
	sem_unlink(SEM_DEATH);
	sem_unlink(SEM_MEALS);
	return (EXIT_SUCCESS);
}
