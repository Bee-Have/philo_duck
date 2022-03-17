/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:08:45 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/17 18:16:46 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_manager(int ac, char **av, long *philo_nbr, t_info *info)
{
	if (ac < 5 || ac > 6)
	{
		error_manager(ERNO_FORMAT);
		return (EXIT_FAILURE);
	}
	*philo_nbr = am_atol(av[1]);
	info->time_die = am_atol(av[2]);
	info->time_eat = am_atol(av[3]);
	info->time_sleep = am_atol(av[4]);
	if (ac == 6)
	{
		info->must_eat = am_atol(av[5]);
		if (info->must_eat <= 0 || info->must_eat > INT_MAX)
		{
			error_manager(ERNO_ARGS);
			return (EXIT_FAILURE);
		}
	}
	else
		info->must_eat = -1;
	if (*philo_nbr <= 0 || *philo_nbr > INT_MAX || info->time_die <= 0
		|| info->time_die > INT_MAX || info->time_eat <= 0
		|| info->time_eat > INT_MAX || info->time_sleep <= 0
		|| info->time_sleep > INT_MAX)
	{
		error_manager(ERNO_ARGS);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
