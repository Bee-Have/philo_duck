/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:57:35 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/25 15:25:04 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>

# define ERNO_FORMAT 0
# define ERNO_ARGS 1

# define MSG_FORK 0
# define MSG_EAT 1
# define MSG_SLEEP 2
# define MSG_THINK 3
# define MSG_DIED 4

typedef struct s_info
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	time;
	pthread_mutex_t	death;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			must_eat;
	long			nbrp;
	int				dead;
}				t_info;

typedef struct s_philo
{
	int				id;
	int				ate;
	long			last_meal;
	pthread_mutex_t	meal;
	t_info			*info;
}				t_philo;

//init
t_philo	*init_philo(t_info *info, pthread_t **tid);

//mutex
int		init_mutexs(t_info *info);
void	destroy_mutexs(t_info *info, t_philo *philo);

//time
long	get_current_time(void);

//print
int		print_action(t_info *info, int id, int action);
char	*format_msg(long lapsed_time, int id, int action);

//parsing arguments
int		args_manager(int ac, char **av, t_info *info);

//routine
//god
void	*god_routine(void *humans);
int		check_all_alive(t_info *all_info, t_philo *philo);
int		check_all_ate(t_info *all_info, t_philo *philo);
//philos
int		wait_time(long given, t_info *info);

void	*eat_routine(void *var);
void	lock_fork_mutex(t_philo *philo);
void	unlock_fork_mutex(t_philo *philo);

void	sleep_routine(t_philo *philo);

//tools
//	strings
int		am_strlen(char *str);
char	*am_strdup(char *str);
char	*am_strjoin(char *prefix, char *sufix);
//	nbrs
char	*am_ltoa(long nbr);
long	am_atol(char *str);

//error
void	error_manager(int erno);

#endif