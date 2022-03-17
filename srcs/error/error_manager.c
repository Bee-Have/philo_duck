/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:16:20 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/17 18:06:53 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_manager(int erno)
{
	char	*msg;

	msg = NULL;
	if (erno == ERNO_FORMAT)
		msg = am_strdup("Error: Wrong number of arguments\n"
						"Usage: ./philo number_of_philosophers time_to_die "
						"time_to_eat time_to_sleep "
						"[number_of_times_each_philosopher_must_eat]\n");
	else if (erno == ERNO_ARGS)
		msg = am_strdup("Error: Wrong argument type or value\n"
						"Warning: Args must me between 1 and MAX_INT\n");
	write(STDERR_FILENO, msg, am_strlen(msg));
	free(msg);
}
