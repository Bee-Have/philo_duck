/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:01:13 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/23 16:40:14 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_info *info, pthread_t **tid)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int			i;

	i = 0;
	*tid = (pthread_t *)malloc((info->nbrp + 1) *sizeof(pthread_t));
	if (!(*tid))
		return (NULL);
	philo = (t_philo *)malloc(info->nbrp * sizeof(t_philo));
	if (!philo)
	{
		free(tid);
		return (NULL);
	}
	forks = (pthread_mutex_t *)malloc(info->nbrp * sizeof(pthread_mutex_t));
	if (!forks)
	{
		free(tid);
		free(philo);
		return (NULL);
	}
	info->forks = forks;
	while (i < info->nbrp)
	{
		pthread_mutex_init(&(info->forks[i]), NULL);
		philo[i].id = i;
		philo[i].info = info;
		philo[i].last_meal = 0;
		++i;
	}
	return (philo);
}
