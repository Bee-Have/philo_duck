/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:21:11 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/01 00:09:48 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	init_philo(t_philo *philo)
{
	philo->id = 0;
	philo->dead = 0;
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
	if (args_manager(ac, av, &info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philo.info = &info;
	init_philo(&philo);
	philo.sem_forks = sem_open(SEM_FORKS, O_CREAT, 0777, philo.info->nbrp);
	philo.sem_pick_fork = sem_open(SEM_PICK_FORK, O_CREAT, 0777, 1);
	philo.sem_death = sem_open(SEM_DEATH, O_CREAT, 0777, 0);
	pid = (pid_t *)malloc((philo.info->nbrp + 1) * sizeof(pid_t));
	if (!pid)
		return (EXIT_FAILURE);
	// sem_wait(philo.sem_death);
	i = 0; 
	while (i < philo.info->nbrp)
	{
		philo.id = i;
		pid[i] = fork();
		if (pid[i] == 0)
			init_routine(&philo);
		++i;
	}
	i = 0;
	death_routine(pid, &philo);
	while (i < philo.info->nbrp)
	{
		waitpid(pid[i], &err, WUNTRACED);
		printf("exit-[%d]\n", WIFEXITED(err));
		++i;
	}
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PICK_FORK);
	sem_unlink(SEM_DEATH);
	return (EXIT_SUCCESS);
}
