/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:12:34 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/18 14:40:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_routine(void *var)
{
	t_philo	*philo;
	long	time;

	time = 0;
	//check if last meal time is over time_die
		//if it is, kill philo
	print_action_time(philo->id, MSG_FORK);
	print_action_time(philo->id, MSG_FORK);
	//mutex buisness
	//after mutex, check if the time does not exceed time_die
		//if it does, kill philo
	print_action_time(philo->id, MSG_EAT);
	while (time < philo->info.time_eat)
	{
		usleep(1000);
		//check if philo died
		++time;
	}
	philo->last_meal = get_current_time();
	//call sleep function
}
