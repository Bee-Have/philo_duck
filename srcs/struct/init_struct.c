/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:01:13 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/17 19:59:20 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(long philo_nbr, t_info info, pthread_t **tid)
{
	t_philo		*philo;
	int			i;

	i = 0;
	*tid = (pthread_t *)malloc(philo_nbr *sizeof(pthread_t));
	if (!(*tid))
		return (NULL);
	philo = (t_philo *)malloc(philo_nbr * sizeof(t_philo));
	if (!philo)
	{
		free(tid);
		return (NULL);
	}
	while (i < philo_nbr)
	{
		philo[i].id = i;
		philo[i].info = info;
		++i;
	}
	return (philo);
}
