/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:11:50 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/30 19:49:34 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat_routine(t_info *info)
{
	long	start;
	long	lapsed;

	start = get_current_time();
	lapsed = start;
	if (sem_wait(info->sem_forks) < 0)
	{
		printf("error sem_wait() child\n");
		exit (EXIT_FAILURE);
	}
	print_action(info, MSG_FORK_ON);
	if (sem_wait(info->sem_forks) < 0)
	{
		printf("error sem_wait() child\n");
		exit (EXIT_FAILURE);
	}
	print_action(info, MSG_FORK_ON);
	print_action(info, MSG_EAT);
	while ((lapsed - start) < info->time_eat)
	{
		lapsed = get_current_time();
		if ((lapsed - start) >= info->time_eat)
			break ;
		usleep(1000);
		lapsed = get_current_time();
	}
	if (sem_post(info->sem_forks) < 0)
	{
		printf("error sem_post() child\n");
		exit (EXIT_FAILURE);
	}
	if (sem_post(info->sem_forks) < 0)
	{
		printf("error sem_post() child\n");
		exit (EXIT_FAILURE);
	}
	sleep_routine(info);
}
