/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:31:35 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/26 17:33:23 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_time(long given, t_info *info)
{
	long	time;
	long	test;

	test = get_current_time();
	time = 0;
	while (time < given)
	{
		if (philo_check_death(info) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if ((get_current_time() - test) >= given)
			break ;
		usleep(1000);
		++time;
	}
	return (EXIT_SUCCESS);
}
