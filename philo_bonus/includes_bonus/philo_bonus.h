/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:34:26 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/30 15:58:03 by amarini-         ###   ########.fr       */
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
# include <errno.h>

# define ERNO_FORMAT 0
# define ERNO_ARGS 1

typedef struct	s_info
{
	pthread_mutex_t	death;
	int				dead;
	long			nbrp;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			must_eat;
}				t_info;

//parsing
int		args_manager(int ac, char **av, t_info *info);

//init
int		init_info(int ac, char **av, t_info *info);

//?			tools
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