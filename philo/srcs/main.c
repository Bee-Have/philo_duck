/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:40:47 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/06 05:09:48 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_t	*tid;
	t_philo		*philo;
	t_info		info;
	int			i;

	if (args_manager(ac, av, &info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	philo = init_philo(&info, &tid);
	if (!philo)
		return (EXIT_FAILURE);
	print_action(&info, 0, MSG_START);
	while (i < info.nbrp)
	{
		philo[i].id = i;
		philo[i].last_meal = get_current_time();
		pthread_create(&(tid[i]), NULL, eat_routine, &(philo[i]));
		++i;
	}
	pthread_create(&(tid[philo->info->nbrp]), NULL, god_routine, philo);
	finish_simulation(&info, philo, tid);
	return (EXIT_SUCCESS);
}

void	finish_simulation(t_info *info, t_philo *philo, pthread_t *tid)
{
	int	i;

	i = 0;
	while (i < info->nbrp + 1)
	{
		pthread_join(tid[i], NULL);
		++i;
	}
	i = 0;
	while (i < info->nbrp)
	{
		pthread_mutex_destroy(&(info->forks[i]));
		pthread_mutex_destroy(&(philo[i].meal));
		pthread_mutex_destroy(&(philo[i].meals_n));
		++i;
	}
	pthread_mutex_destroy(&info->time);
	pthread_mutex_destroy(&info->death);
	free(info->forks);
	free(tid);
	free(philo);
}
