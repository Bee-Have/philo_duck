/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:35:32 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/09 02:26:39 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	args_manager(int ac, char **av, t_info *info)
{
	if (ac < 5 || ac > 6)
	{
		error_manager(ERNO_FORMAT);
		return (-1);
	}
	if (init_info(ac, av, info) == EXIT_FAILURE
		|| info->nbrp <= 0 || info->nbrp > 200)
	{
		error_manager(ERNO_PHILO);
		return (EXIT_FAILURE);
	}
	else if (init_info(ac, av, info) == EXIT_FAILURE
		|| info->time_die <= 0 || info->time_die > INT_MAX
		|| info->time_eat <= 0 || info->time_eat > INT_MAX
		|| info->time_sleep <= 0 || info->time_sleep > INT_MAX)
	{
		error_manager(ERNO_ARGS);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
