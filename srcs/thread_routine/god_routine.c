/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:48:16 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/23 17:55:55 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*god_routine(void *humans)
{
	t_philo	*philo;
	t_info	*all_info;

	philo = (t_philo *)humans;
	all_info = philo[0].info;
	while (all_info->dead == 0)
	{
		if (check_all_alive(all_info, philo) == EXIT_FAILURE
			|| (all_info->must_eat != -1
				&& check_all_ate(all_info, philo) == EXIT_FAILURE))
			break ;
	}
	return (NULL);
}

int	check_all_alive(t_info *all_info, t_philo *philo)
{
	long	elapsed;
	int		i;

	i = 0;
	elapsed = 0;
	while (i < all_info->nbrp)
	{
		elapsed = get_current_time() - philo[i].last_meal;
		if (elapsed >= all_info->time_die)
		{
			print_action_time(philo[i].id, MSG_DIED);
			all_info->dead = 1;
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	check_all_ate(t_info *all_info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < all_info->nbrp)
	{
		if (philo[i].ate < all_info->must_eat)
			return (EXIT_SUCCESS);
		++i;
	}
	return (EXIT_FAILURE);
}
