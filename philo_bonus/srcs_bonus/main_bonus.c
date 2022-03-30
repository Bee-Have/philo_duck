/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:21:11 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/30 19:46:58 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int ac, char **av)
{
	t_info	info;
	pid_t	*pid;
	int		err;
	int		i;

	sem_unlink(SEM_FORKS);
	if (args_manager(ac, av, &info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	info.sem_forks = sem_open(SEM_FORKS, O_CREAT, 0777, info.nbrp);
	if (info.sem_forks == SEM_FAILED)
	{
		printf("ERROR : sem_open failed\n");
		return (EXIT_FAILURE);
	}
	pid = (pid_t *)malloc(info.nbrp * sizeof(pid_t));
	if (!pid)
		return (EXIT_FAILURE);
	i = 0;
	while (i < info.nbrp)
	{
		info.id = i;
		pid[i] = fork();
		if (pid[i] == 0)
			eat_routine(&info);
		++i;
	}
	i = 0;
	sleep(5);
	while(i < info.nbrp)
	{
		kill(pid[i], SIGKILL);
		++i;
	}
	i = 0;
	while (i < info.nbrp)
	{
		waitpid(-1, &err, 0);
		printf("exit-[%d]\n", WIFEXITED(err));
		++i;
	}
	if (sem_unlink(SEM_FORKS))
	return (EXIT_SUCCESS);
}
