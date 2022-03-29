/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:20:32 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/29 20:01:56 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

#define SEM_NAME "/sem_example"

typedef struct	s_test
{
	int	id;
}				t_test;

void	testing_sems(t_test *testing)
{
	sem_t	*sem_test;

	sem_test = sem_open(SEM_NAME, O_CREAT, 0777, 2);
	if (sem_test == SEM_FAILED)
	{
		printf("ERROR : [%s] : child sem_open() Failed\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("SUCCESS : child sem_open() worked\n");
	if (sem_wait(sem_test) < 0)
	{
		printf("ERROR : [%s] : child sem_wait() Failed\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("SUCCESS : child sem_wait() worked\n");
	printf("[%d] has taken a fork\n", testing->id);
	if (sem_post(sem_test) < 0)
	{
		printf("ERROR : [%s] : child sem_post() Failed\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("SUCCESS : child sem_post() worked\n");
	printf("[%d] has freed a fork\n", testing->id);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	pid_t	pid[2];
	sem_t	*sem;
	t_test	testing;
	int		i;
	int		ret;

	if (sem_unlink(SEM_NAME) < 0)
	{
		printf("ERROR : [%s] : sem_unlink() Failed\n", strerror(errno));
	}
	sem = sem_open(SEM_NAME, O_CREAT, 0777, 2);
	if (sem == SEM_FAILED)
	{
		printf("ERROR : [%s] : sem_open() Failed\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	printf("SUCCESS : sem_open() worked\n");
	i = 0;
	while (i < 2)
	{
		testing.id = i;
		pid[i] = fork();
		if (pid[i] == 0)
		{
			testing_sems(&testing);
			exit(EXIT_SUCCESS);
		}
		++i;
	}
	i = 0;
	while (i < 2)
	{
		waitpid(-1, &ret, WUNTRACED);
		printf("ret_wait-[%d]\n", ret);
		++i;
	}
	if (sem_unlink(SEM_NAME) < 0)
	{
		printf("ERROR : [%s] : sem_unlink() Failed\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
