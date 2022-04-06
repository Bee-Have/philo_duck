/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:17:34 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/06 03:46:27 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

int	print_action(t_philo *philo, int action)
{
	long		current_time;
	char		msg[42];

	am_bzero(msg, 42);
	if (check_death(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	current_time = get_current_time();
	current_time = current_time - philo->info->start_time;
	format_msg(msg, current_time, philo->id + 1, action);
	if (check_death(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	write(STDOUT_FILENO, msg, am_strlen(msg));
	return (EXIT_SUCCESS);
}
