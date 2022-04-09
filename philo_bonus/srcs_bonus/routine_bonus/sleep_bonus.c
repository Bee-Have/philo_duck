/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:36:42 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/09 05:07:27 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sleep_routine(t_philo *philo)
{
	if (check_death(philo) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	if (print_action(philo, MSG_SLEEP) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	if (wait_time(philo->info->time_eat, philo) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (print_action(philo, MSG_THINK) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	if (check_death(philo) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	eat_routine(philo);
}
