/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:14:48 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/01 00:09:21 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	death_routine(pid_t *pid, t_philo *philo)
{
	int	i;

	sem_wait(philo->sem_death);
	i = 0;
	while (i < philo->info->nbrp)
	{
		kill(pid[i], SIGKILL);
		++i;
	}
}
