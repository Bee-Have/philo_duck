/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:33:07 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/17 05:19:39 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*format_msg(long lapsed_time, int id, int action)
{
	char	*str;
	char	*tmp;
	char	*msg;

	str = am_ltoa(lapsed_time);
	tmp = am_ltoa(id + 1);
	msg = am_strjoin(str, " ");
	free(str);
	str = am_strjoin(msg, tmp);
	free(tmp);
	free(msg);
	if (action == MSG_FORK)
		msg = am_strjoin(str, " has taken a fork\n");
	else if (action == MSG_EAT)
		msg = am_strjoin(str, " is eating\n");
	else if (action == MSG_SLEEP)
		msg = am_strjoin(str, " is sleeping\n");
	else if (action == MSG_THINK)
		msg = am_strjoin(str, " is thinking\n");
	else if (action == MSG_DIED)
		msg = am_strjoin(str, " died\n");
	free(str);
	return (msg);
}

// make it thread safe
void	print_action_time(int id, int action)
{
	static long	start_time = 0;
	long		current_time;
	char		*msg;

	current_time = get_current_time();
	if (start_time == 0)
		start_time = current_time;
	current_time = current_time - start_time;
	msg = format_msg(current_time, id, action);
	write(STDOUT_FILENO, msg, am_strlen(msg));
	free(msg);
}
