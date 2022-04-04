/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routine_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:52:54 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/04 18:18:08 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_routine(t_philo *philo)
{
	pthread_t	tid;

	//init mutexs
	pthread_mutex_init(&philo->death, NULL);
	pthread_mutex_init(&philo->meals_n, NULL);
	pthread_mutex_init(&philo->meal, NULL);
	//launch thread
	pthread_create(&tid, NULL, check_vitals, philo);
	//call eat routine
	eat_routine(philo);
	//thread join here
	pthread_join(tid, NULL);
	pthread_mutex_destroy(&philo->death);
	pthread_mutex_destroy(&philo->meals_n);
	pthread_mutex_destroy(&philo->meal);
}