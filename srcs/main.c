/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:40:47 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/17 19:00:05 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_t	tid;
	t_philo		philo;
	t_info		info;
	long		philo_nbr;

	if (args_manager(ac, av, &philo_nbr, &info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//init philo struct
	//start threads
	return (EXIT_SUCCESS);
}
