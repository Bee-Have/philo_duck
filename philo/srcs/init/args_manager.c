/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:08:45 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/06 05:42:42 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_manager(int ac, char **av, t_info *info)
{
	if (ac < 5 || ac > 6)
	{
		error_manager(ERNO_FORMAT);
		return (EXIT_FAILURE);
	}
	if (init_info(ac, av, info) == EXIT_FAILURE
		|| info->nbrp <= 0 || info->nbrp > INT_MAX || info->time_die <= 0
		|| info->time_die > INT_MAX || info->time_eat <= 0
		|| info->time_eat > INT_MAX || info->time_sleep <= 0
		|| info->time_sleep > INT_MAX)
	{
		error_manager(ERNO_ARGS);
		return (EXIT_FAILURE);
	}
	info->dead = 0;
	return (EXIT_SUCCESS);
}
