/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:01:13 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/26 14:59:22 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_info *info, pthread_t **tid)
{
	t_philo			*philo;
	int				i;

	i = 0;
	*tid = (pthread_t *)malloc((info->nbrp + 1) * sizeof(pthread_t));
	if (!(*tid))
		return (NULL);
	philo = (t_philo *)malloc(info->nbrp * sizeof(t_philo));
	if (!philo)
	{
		free(*tid);
		return (NULL);
	}
	if (init_mutexs(info, philo) == EXIT_FAILURE)
	{
		free(*tid);
		return (NULL);
	}
	while (i < info->nbrp)
	{
		philo[i].ate = 0;
		philo[i].info = info;
		++i;
	}
	return (philo);
}

int	init_mutexs(t_info *info, t_philo *philo)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = (pthread_mutex_t *)malloc(info->nbrp * sizeof(pthread_mutex_t));
	if (!forks)
	{
		free(philo);
		return (EXIT_FAILURE);
	}
	info->forks = forks;
	i = 0;
	while (i < info->nbrp)
	{
		pthread_mutex_init(&(philo[i].meal), NULL);
		pthread_mutex_init(&(info->forks[i]), NULL);
		++i;
	}
	pthread_mutex_init(&info->time, NULL);
	pthread_mutex_init(&info->death, NULL);
	return (EXIT_SUCCESS);
}
