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

static void	add_str(char dst[42], char *srcs)
{
	int	i;

	i = 0;
	while (srcs[i] != '\0')
	{
		dst[i] = srcs[i];
		++i;
	}
	dst[i] = '\0';
}

static void	add_nbr(char dst[42], long srcs)
{
	int	i;
	int	nbr;

	i = calc_len(srcs) - 1;
	while (i >= 0)
	{
		nbr = srcs % 10;
		dst[i] = nbr + '0';
		srcs = srcs / 10;
		--i;
	}
}

static void	format_msg(char msg[42], long lapsed_time, int id, int action)
{
	int	len;

	if (action == MSG_START)
	{
		add_str(msg + 0, "starting simulation\n");
		return ;
	}
	add_nbr(msg + 0, lapsed_time);
	len = am_strlen(msg);
	add_str(msg + len, " ");
	add_nbr(msg + (len + 1), id);
	len = am_strlen(msg);
	if (action == MSG_FORK_ON)
		add_str(msg + len, " has taken a fork\n");
	else if (action == MSG_EAT)
		add_str(msg + len, " is eating\n");
	else if (action == MSG_SLEEP)
		add_str(msg + len, " is sleeping\n");
	else if (action == MSG_THINK)
		add_str(msg + len, " is thinking\n");
	else if (action == MSG_DIED)
		add_str(msg + len, " died\n");
}

int	print_action(t_info *info, int id, int action)
{
	static long	start_time = 0;
	long		current_time;
	char		msg[42];

	am_bzero(msg, 42);
	if (philo_check_death(info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	current_time = get_current_time();
	pthread_mutex_lock(&info->time);
	if (start_time == 0)
		start_time = current_time;
	current_time = current_time - start_time;
	pthread_mutex_unlock(&info->time);
	if (philo_check_death(info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	format_msg(msg, current_time, id + 1, action);
	write(STDOUT_FILENO, msg, am_strlen(msg));
	return (EXIT_SUCCESS);
}
