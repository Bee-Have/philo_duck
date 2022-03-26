/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:31:35 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/26 17:42:21 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_time(long given, t_info *info)
{
	long	start;
	long	lapsed;

	start = get_current_time();
	lapsed = start;
	while ((lapsed - start) < given)
	{
		if (philo_check_death(info) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		lapsed = get_current_time();
		if ((lapsed - start) >= given)
			break ;
		usleep(1000);
		lapsed = get_current_time();
	}
	return (EXIT_SUCCESS);
}
