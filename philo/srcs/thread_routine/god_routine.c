/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:48:16 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/05 06:41:22 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	unlock_all_forks(t_info *all_info)
{
	int	i;

	while (i < all_info->nbrp)
	{
		pthread_mutex_unlock(&(all_info->forks[i]));
		++i;
	}
}

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
		{
			pthread_mutex_lock(&philo->info->death);
			all_info->dead = 1;
			pthread_mutex_unlock(&philo->info->death);
			unlock_all_forks(all_info);
			break ;
		}
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
		elapsed = get_current_time() - philo[i].last_meal;
		pthread_mutex_unlock(&(philo[i].meal));
		if (elapsed >= all_info->time_die)
		{
			print_action(all_info, philo[i].id, MSG_DIED);
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
		pthread_mutex_lock(&(philo[i].meals_n));
		if (philo[i].meals_nbr < all_info->must_eat)
		{
			pthread_mutex_unlock(&(philo[i].meals_n));
			return (EXIT_SUCCESS);
		}
		pthread_mutex_unlock(&(philo[i].meals_n));
		++i;
	}
	return (EXIT_FAILURE);
}
