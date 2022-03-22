/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:12:15 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/21 22:41:52 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_routine(t_philo *philo)
{
	long	time;

	time = 0;
	print_action_time(philo->id, MSG_SLEEP);
	while (time < philo->info->time_sleep)
	{
		usleep(1000);
		//check if philo died
		++time;
	}
	print_action_time(philo->id, MSG_THINK);
	//call eat
	eat_routine((void *)philo);
}
