/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:35:32 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/31 20:02:05 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	init_info(int ac, char **av, t_info *info)
{
	info->nbrp = am_atol(av[1]);
	info->time_die = am_atol(av[2]);
	info->time_eat = am_atol(av[3]);
	info->time_sleep = am_atol(av[4]);
	if (ac == 6)
	{
		info->must_eat = am_atol(av[5]);
		if (info->must_eat <= 0 || info->must_eat > INT_MAX)
			return (EXIT_FAILURE);
	}
	else
		info->must_eat = -1;
	return (EXIT_SUCCESS);
}

int	args_manager(int ac, char **av, t_info *info)
{
	if (ac < 5 || ac > 6)
	{
		error_manager(ERNO_FORMAT);
		return (-1);
	}
	if (init_info(ac, av, info) == EXIT_FAILURE
		|| info->nbrp <= 0 || info->nbrp > INT_MAX
		|| info->time_die <= 0 || info->time_die > INT_MAX
		|| info->time_eat <= 0 || info->time_eat > INT_MAX
		|| info->time_sleep <= 0 || info->time_sleep > INT_MAX)
	{
		error_manager(ERNO_ARGS);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
