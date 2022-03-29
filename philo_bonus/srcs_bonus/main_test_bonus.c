/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:20:32 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/29 17:52:59 by amarini-         ###   ########.fr       */
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

	sem_test = sem_open(SEM_NAME, O_CREAT, S_IROTH | S_IWOTH, 2);
	if (sem_test == SEM_FAILED)
	{
		printf("ERROR : child sem_open() Failed\n");
		exit(EXIT_FAILURE);
	}
	if (sem_wait(sem_test) < 0)
	{
		printf("ERROR : child sem_wait() Failed\n");
		exit(EXIT_FAILURE);
	}
	printf("[%d] has taken a fork\n", testing->id);
	if (sem_wait(sem_test) < 0)
	{
		printf("ERROR : child sem_wait() Failed\n");
		exit(EXIT_FAILURE);
	}
	printf("[%d] has taken a fork\n", testing->id);
	if (sem_post(sem_test) < 0)
	{
		printf("ERROR : child sem_post() Failed\n");
		exit(EXIT_FAILURE);
	}
	printf("[%d] has freed a fork\n", testing->id);
	if (sem_post(sem_test) < 0)
	{
		printf("ERROR : child sem_post() Failed\n");
		exit(EXIT_FAILURE);
	}
	printf("[%d] has freed a fork\n", testing->id);
}

int	main(void)
{
	pid_t	pid[2];
	sem_t	*sem;
	t_test	testing;
	int		i;
	int		ret;

	sem = sem_open(SEM_NAME, O_CREAT, S_IROTH | S_IWOTH, 1);
	if (sem == SEM_FAILED)
	{
		printf("ERROR : sem_open() Failed\n");
		return (EXIT_FAILURE);
	}
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
		waitpid(pid[i], &ret, WUNTRACED);
		printf("ret_wait-[%d]\n", ret);
	}
	return (EXIT_SUCCESS);
}
