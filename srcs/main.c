/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:40:47 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/24 19:00:51 by amarini-         ###   ########.fr       */
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
	while (i < info.nbrp)
	{
		pthread_create(&(tid[i]), NULL, eat_routine, &(philo[i]));
		++i;
	}
	pthread_create(&(tid[i]), NULL, god_routine, philo);
	i = 0;
	while (i < info.nbrp + 1)
	{
		pthread_join(tid[i], NULL);
		if (i < info.nbrp)
			pthread_mutex_destroy(&info.forks[i]);
		++i;
	}
	pthread_mutex_destroy(&info.time);
	free(tid);
	free(philo);
	free(info.forks);
	return (EXIT_SUCCESS);
}
