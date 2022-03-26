/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:33:07 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/23 19:57:04 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*get_msg(int action)
{
	char	*str;

	if (action == MSG_FORK_ON)
		str = am_strdup("] has taken a fork\n");
	else if (action == MSG_EAT)
		str = am_strdup("] is eating\n");
	else if (action == MSG_SLEEP)
		str = am_strdup("] is sleeping\n");
	else if (action == MSG_THINK)
		str = am_strdup("] is thinking\n");
	else if (action == MSG_DIED)
		str = am_strdup("] died\n");
	return (str);
}

char	*format_msg(long lapsed_time, int id, int action)
{
	char	*str;
	char	*tmp;
	char	*msg;

	str = am_ltoa(lapsed_time);
	tmp = am_strjoin("time-[", str);
	free(str);
	msg = am_strjoin(tmp, "] id-[");
	free(tmp);
	tmp = am_ltoa(id + 1);
	str = am_strjoin(msg, tmp);
	free(tmp);
	free(msg);
	tmp = get_msg(action);
	msg = am_strjoin(str, tmp);
	free(tmp);
	free(str);
	return (msg);
}

// make it thread safe
int	print_action(t_info *info, int id, int action)
{
	static long	start_time = 0;
	long		current_time;
	char		*msg;

	if (philo_check_death(info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	current_time = get_current_time();
	pthread_mutex_lock(&info->time);
	if (start_time == 0)
		start_time = current_time;
	current_time = current_time - start_time;
	pthread_mutex_unlock(&info->time);
	msg = format_msg(current_time, id, action);
	if (philo_check_death(info) == EXIT_FAILURE)
	{
		free(msg);
		return (EXIT_FAILURE);
	}
	write(STDOUT_FILENO, msg, am_strlen(msg));
	free(msg);
	return (EXIT_SUCCESS);
}
