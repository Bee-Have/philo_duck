/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:01:13 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/22 02:09:23 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_info *info, pthread_t **tid)
{
	t_philo		*philo;
	int			i;

	i = 0;
	*tid = (pthread_t *)malloc(info->nbrp *sizeof(pthread_t));
	if (!(*tid))
		return (NULL);
	philo = (t_philo *)malloc(info->nbrp * sizeof(t_philo));
	if (!philo)
	{
		free(tid);
		return (NULL);
	}
	pthread_mutex_init(&info->forks, NULL);
	while (i < info->nbrp)
	{
		philo[i].id = i;
		philo[i].info = info;
		philo[i].last_meal = 0;
		++i;
	}
	return (philo);
}
