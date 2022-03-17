/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:57:35 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/17 04:56:44 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>

# define MSG_FORK 0
# define MSG_EAT 1
# define MSG_SLEEP 2
# define MSG_THINK 3
# define MSG_DIED 4

typedef struct s_info
{
	long	time_die;
	long	time_eat;
	long	time_sleep;
	long	must_eat;
}				t_info;

typedef struct s_philo
{
	int	id;
}				t_philo;

//time
long	get_current_time(void);

//print
void	print_action_time(int id, int action);
char	*format_msg(long lapsed_time, int id, int action);

//tools
//	strings
int		am_strlen(char *str);
char	*am_strdup(char *str);
char	*am_strjoin(char *prefix, char *sufix);
//	nbrs
char	*am_ltoa(long nbr);
long	am_atol(char *str);

#endif