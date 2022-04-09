/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:35:42 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/09 05:07:53 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	wait_time(long given, t_philo *philo)
{
	long	start;
	long	lapsed;

	if (check_death(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	start = get_current_time();
	lapsed = start;
	while ((lapsed - start) < given)
	{
		if (check_death(philo) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		lapsed = get_current_time();
		if ((lapsed - start) >= given)
			break ;
		usleep(1000);
		lapsed = get_current_time();
	}
	if (check_death(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
