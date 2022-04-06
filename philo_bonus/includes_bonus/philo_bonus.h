/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:34:26 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/06 06:12:12 by amarini-         ###   ########.fr       */
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

# define SEM_DEATH "/sem_death"
# define SEM_PICK_FORK "/sem_pick_fork"
# define SEM_FORKS "/sem_fork"
# define SEM_MEALS "/sem_meals"
# define SEM_WRITE "/sem_write"

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
	long			start_time;
	long			nbrp;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			must_eat;
}				t_info;

typedef struct s_philo
{
	sem_t			*sem_death;
	sem_t			*sem_pick_fork;
	sem_t			*sem_forks;
	sem_t			*sem_meals;
	sem_t			*sem_write;
	int				id;
	t_info			*info;
	pthread_mutex_t	death;
	pthread_mutex_t	meals_n;
	pthread_mutex_t	meal;
	int				dead;
	int				meals_nbr;
	long			last_meal;
}				t_philo;

//?			managments
//parsing
int		args_manager(int ac, char **av, t_info *info);
//init / malloc
int		init_info(int ac, char **av, t_info *info);
int		init_philo(t_philo *philo, pid_t **pid);
void	init_semaphores(t_philo *philo);

//?			routine
//init
void	init_routine(t_philo *philo);
//vitals
void	*check_vitals(void *human);
void	check_meals_nbr(t_philo *philo);
int		check_death(t_philo *philo);
//general
void	check_meals_routine(t_philo *philo);
void	death_routine(pid_t *pid, t_philo *philo);
int		wait_time(long given, t_philo *philo);
//eat
void	eat_routine(t_philo *philo);
void	pick_up_forks(t_philo *philo);
void	eat(t_philo *philo);
//sleep/think
void	sleep_routine(t_philo *philo);

//print
int		print_action(t_philo *philo, int action);

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

//!			error
void	error_manager(int erno);

#endif