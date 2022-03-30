/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:17:34 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/30 17:50:38 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static char	*get_msg(int action)
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

static char	*format_msg(long lapsed_time, int id, int action)
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

void	print_action(t_info *info, int action)
{
	static long	start_time = 0;
	long		current_time;
	char		*msg;

	current_time = get_current_time();
	if (start_time == 0)
		start_time = current_time;
	current_time = current_time - start_time;
	msg = format_msg(current_time, info->id, action);
	write(STDOUT_FILENO, msg, am_strlen(msg));
	free(msg);
}
