/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:29:19 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/26 14:39:37 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_check_death(t_info *info)
{
	pthread_mutex_lock(&info->death);
	if (info->dead == 1)
	{
		pthread_mutex_unlock(&info->death);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&info->death);
	return (EXIT_SUCCESS);
}
