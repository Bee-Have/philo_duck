/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:31:35 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/23 17:52:56 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_time(long given, int *dead)
{
	long	time;

	time = 0;
	while (time < given)
	{
		if (*dead == 1)
			return (EXIT_FAILURE);
		usleep(1000);
		++time;
	}
	return (EXIT_SUCCESS);
}
