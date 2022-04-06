/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:57:35 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/06 05:09:45 by amarini-         ###   ########.fr       */
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

# define MSG_START 0
# define MSG_FORK_ON 1
# define MSG_EAT 2
# define MSG_SLEEP 3
# define MSG_THINK 4
# define MSG_DIED 5

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
	int				meals_nbr;
	long			last_meal;
	pthread_mutex_t	meal;
	pthread_mutex_t	meals_n;
	t_info			*info;
}				t_philo;

//parsing arguments
int		args_manager(int ac, char **av, t_info *info);

//?			managments
//init / malloc
int		init_info(int ac, char **av, t_info *info);
t_philo	*init_philo(t_info *info, pthread_t **tid);
int		init_mutexs(t_info *info, t_philo *philo);
//destroy / free
void	finish_simulation(t_info *info, t_philo *philo, pthread_t *tid);

//print
int		print_action(t_info *info, int id, int action);

//?			routine
//god
void	*god_routine(void *humans);
int		god_check_vitals(t_info *all_info, t_philo *philo);
int		god_check_meals(t_info *all_info, t_philo *philo);
//?		philos
//all philos
int		philo_check_death(t_info *info);
int		wait_time(long given, t_info *info);
//eat
void	*eat_routine(void *var);
int		print_meal_actions(t_philo *philo);
int		lock_fork_mutex(t_philo *philo);
void	unlock_fork_mutex(t_philo *philo);
//sleep / think
void	sleep_routine(t_philo *philo);

//?			tools
//time
long	get_current_time(void);
//strings
int		am_strlen(char *str);
char	*am_strdup(char *str);
char	*am_strjoin(char *prefix, char *sufix);
void	am_bzero(char *str, int len);
//nbrs
int		calc_len(long nbr);
char	*am_ltoa(long nbr);
long	am_atol(char *str);

//!error
void	error_manager(int erno);

#endif