/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:12:15 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/23 17:55:18 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_routine(t_philo *philo)
{
	if (philo->info->dead == 1)
		return ;
	print_action_time(philo->id, MSG_SLEEP);
	if (wait_time(philo->info->time_sleep, &philo->info->dead) == EXIT_FAILURE)
		return ;
	print_action_time(philo->id, MSG_THINK);
	eat_routine((void *)philo);
}
