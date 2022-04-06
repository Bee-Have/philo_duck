/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:12:15 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/06 02:09:27 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_routine(t_philo *philo)
{
	if (print_action(philo->info, philo->id, MSG_SLEEP) == EXIT_FAILURE)
		return ;
	if (wait_time(philo->info->time_sleep, philo->info) == EXIT_FAILURE)
		return ;
	if (print_action(philo->info, philo->id, MSG_THINK) == EXIT_FAILURE)
		return ;
	if (philo->info->time_die - (get_current_time() - philo->last_meal) <= 15)
		wait_time(1, philo->info);
	else
		wait_time(5, philo->info);
	eat_routine((void *)philo);
}
