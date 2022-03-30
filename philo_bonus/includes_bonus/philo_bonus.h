/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:34:26 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/30 19:46:36 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <limits.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <signal.h>
# include <errno.h>

#define SEM_DEATH "/sem_death"
#define SEM_FORKS "/sem_fork"

# define ERNO_FORMAT 0
# define ERNO_ARGS 1

# define MSG_FORK_ON 0
# define MSG_EAT 1
# define MSG_SLEEP 2
# define MSG_THINK 3
# define MSG_DIED 4

typedef struct	s_info
{
	sem_t			*sem_forks;
	pthread_mutex_t	death;
	int				dead;
	int				id;
	long			nbrp;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			must_eat;
}				t_info;

//parsing
int		args_manager(int ac, char **av, t_info *info);

//?			routine
//eat
void	eat_routine(t_info *info);
//sleep
void	sleep_routine(t_info *info);

//print
void	print_action(t_info *info, int action);

//?			tools
//time
long	get_current_time(void);
//strings
int		am_strlen(char *str);
char	*am_strdup(char *str);
char	*am_strjoin(char *prefix, char *sufix);
//nbrs
char	*am_ltoa(long nbr);
long	am_atol(char *str);

//!			error
void	error_manager(int erno);

#endif