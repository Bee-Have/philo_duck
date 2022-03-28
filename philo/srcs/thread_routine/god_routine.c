/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:48:16 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/26 17:16:05 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*god_routine(void *humans)
{
	t_philo	*philo;
	t_info	*all_info;

	philo = (t_philo *)humans;
	all_info = philo[0].info;
	while (1)
	{
		if (god_check_vitals(all_info, philo) == EXIT_FAILURE
			|| (all_info->must_eat != -1
				&& god_check_meals(all_info, philo) == EXIT_FAILURE))
			break ;
		usleep(1000);
	}
	return (NULL);
}

int	god_check_vitals(t_info *all_info, t_philo *philo)
{
	long	elapsed;
	int		i;

	i = 0;
	elapsed = 0;
	while (i < all_info->nbrp)
	{
		pthread_mutex_lock(&(philo[i].meal));
		if (philo[i].last_meal == 0)
			elapsed = 0;
		else
			elapsed = get_current_time() - philo[i].last_meal;
		pthread_mutex_unlock(&(philo[i].meal));
		if (elapsed >= all_info->time_die)
		{
			print_action(all_info, philo[i].id, MSG_DIED);
			pthread_mutex_lock(&philo->info->death);
			all_info->dead = 1;
			pthread_mutex_unlock(&philo->info->death);
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	god_check_meals(t_info *all_info, t_philo *philo)
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