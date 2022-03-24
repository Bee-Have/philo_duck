/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:01:13 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/24 19:20:15 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_info *info, pthread_t **tid)
{
	t_philo			*philo;
	int				i;

	i = 0;
	if (init_mutexs(info) == EXIT_FAILURE)
		return (NULL);
	*tid = (pthread_t *)malloc((info->nbrp + 1) * sizeof(pthread_t));
	if (!(*tid))
	{
		free(info->forks);
		return (NULL);
	}
	philo = (t_philo *)malloc(info->nbrp * sizeof(t_philo));
	if (!philo)
	{
		free(info->forks);
		free(tid);
		return (NULL);
	}
	while (i < info->nbrp)
	{
		pthread_mutex_init(&(philo[i].meal), NULL);
		philo[i].id = i;
		philo[i].ate = 0;
		philo[i].last_meal = 0;
		philo[i].info = info;
		++i;
	}
	return (philo);
}

int	init_mutexs(t_info *info)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = (pthread_mutex_t *)malloc(info->nbrp * sizeof(pthread_mutex_t));
	if (!forks)
		return (EXIT_FAILURE);
	info->forks = forks;
	i = 0;
	while (i < info->nbrp)
	{
		pthread_mutex_init(&(info->forks[i]), NULL);
		++i;
	}
	pthread_mutex_init(&info->time, NULL);
	return (EXIT_SUCCESS);
}
