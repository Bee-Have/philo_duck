/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:36:42 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/30 19:26:39 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sleep_routine(t_info *info)
{
	long	start;
	long	lapsed;

	start = get_current_time();
	lapsed = start;
	print_action(info, MSG_SLEEP);
	while ((lapsed - start) < info->time_eat)
	{
		lapsed = get_current_time();
		if ((lapsed - start) >= info->time_eat)
			break ;
		usleep(1000);
		lapsed = get_current_time();
	}
	print_action(info, MSG_THINK);
	//call function eat
	eat_routine(info);
}
