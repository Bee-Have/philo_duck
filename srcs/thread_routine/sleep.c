/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:12:15 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/26 17:06:16 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_routine(t_philo *philo)
{
	if (philo_check_death(philo->info) == EXIT_FAILURE)
		return ;
	if (print_action(philo->info, philo->id, MSG_SLEEP) == EXIT_FAILURE)
		return ;
	if (wait_time(philo->info->time_sleep, philo->info) == EXIT_FAILURE)
		return ;
	if (print_action(philo->info, philo->id, MSG_THINK) == EXIT_FAILURE)
		return ;
	if (philo_check_death(philo->info) == EXIT_FAILURE)
	return ;
	eat_routine((void *)philo);
}
