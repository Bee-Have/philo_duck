/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:40:10 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/09 02:24:18 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	error_manager(int erno)
{
	char	*msg;

	msg = NULL;
	if (erno == ERNO_FORMAT)
		msg = am_strdup("Error: Wrong number of arguments\n"
				"Usage: ./philo number_of_philosophers time_to_die "
				"time_to_eat time_to_sleep "
				"[number_of_times_each_philosopher_must_eat]\n");
	else if (erno == ERNO_PHILO)
		msg = am_strdup("Error: Wrong argument type or value\n"
				"Warning: First arg must me between 1 and 200\n");
	else if (erno == ERNO_ARGS)
		msg = am_strdup("Error: Wrong argument type or value\n"
				"Warning: Args must me between 1 and MAX_INT\n");
	write(STDERR_FILENO, msg, am_strlen(msg));
	free(msg);
}
