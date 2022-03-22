/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:48:16 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/22 02:33:17 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*god_routine(void *humans)
{
	t_philo	*philo;
	t_info	*all_info;
	long	elapsed;
	int		i;

	philo = (t_philo *)humans;
	all_info = philo[0].info;
	while (all_info->dead == 0)
	{
		i = 0;
		while (i < all_info->nbrp)
		{
			elapsed = get_current_time() - philo[i].last_meal;
			if (elapsed >= all_info->time_die)
			{
				//print death of philo[i]
				all_info->dead = 1;
				break ;
			}
			++i;
		}
	}
}

int	check_all_ate(t_info *all_info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < all_info->nbrp)
	{
		if (philo[i].ate < all_info->must_eat)
			return (0);
		++i;
	}
	return (1);
}
