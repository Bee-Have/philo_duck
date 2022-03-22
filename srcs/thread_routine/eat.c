/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:12:34 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/22 02:10:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eat_routine(void *var)
{
	t_philo	*philo;
	long	time;

	philo = (t_philo *)var;
	time = get_current_time();
	//check if last meal time is over time_die
		//if it is, kill philo
	print_action_time(philo->id, MSG_FORK);
	print_action_time(philo->id, MSG_FORK);
	//mutex buisness
	print_action_time(philo->id, MSG_EAT);
	//after mutex, check if the time does not exceed time_die
		//if it does, kill philo
	while (time < philo->info->time_eat)
	{
		usleep(1000);
		//check if philo died
		++time;
	}
	philo->last_meal = get_current_time();
	//call sleep function
	sleep_routine(philo);
	return (NULL);
}
