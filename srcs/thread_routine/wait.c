/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:31:35 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/25 15:31:43 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_time(long given, t_info *info)
{
	long	time;

	// pthread_mutex_lock(&info->death);
	if (info->dead == 1)
		return (EXIT_FAILURE);
	// pthread_mutex_unlock(&info->death);
	time = 0;
	while (time < given)
	{
		// pthread_mutex_lock(&info->death);
		if (info->dead == 1)
			return (EXIT_FAILURE);
		// pthread_mutex_unlock(&info->death);
		usleep(1000);
		++time;
	}
	// pthread_mutex_lock(&info->death);
	if (info->dead == 1)
		return (EXIT_FAILURE);
	// pthread_mutex_unlock(&info->death);
	return (EXIT_SUCCESS);
}
