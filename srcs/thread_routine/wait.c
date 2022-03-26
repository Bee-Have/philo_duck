/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:31:35 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/26 14:39:31 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_time(long given, t_info *info)
{
	long	time;

	if (philo_check_death(info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	time = 0;
	while (time < given)
	{
		if (philo_check_death(info) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		usleep(1000);
		++time;
	}
	if (philo_check_death(info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
