/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:40:47 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/18 14:18:36 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*my_thread(void *test)
{
	t_philo	*tmp;

	tmp = (t_philo *)test;
	print_action_time((*tmp).id, MSG_SLEEP);
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	*tid;
	t_philo		*philo;
	t_info		info;
	long		philo_nbr;
	int			i;

	if (args_manager(ac, av, &philo_nbr, &info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	philo = init_philo(philo_nbr, info, &tid);
	if (!philo)
		return (EXIT_FAILURE);
	while (i < philo_nbr)
	{
		pthread_create(&(tid[i]), NULL, my_thread, &(philo[i]));
		++i;
	}
	i = 0;
	while (i < philo_nbr)
	{
		pthread_join(tid[i], NULL);
		++i;
	}
	free(tid);
	free(philo);
	return (EXIT_SUCCESS);
}
