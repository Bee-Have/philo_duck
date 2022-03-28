/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:20:32 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/28 18:29:24 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

#define SEM_NAME "/sem_example"

typedef struct	s_test
{
	int	test;
}				t_test;

void	testing_sems(t_test *testing)
{
	sem_t	*sem_test;

	sem_test = sem_open(SEM_NAME, O_CREAT, S_IROTH | S_IWOTH, 1);
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
	testing->test += 1;
	if (sem_post(sem_test) < 0)
	{
		printf("ERROR : child sem_post() Failed\n");
		exit(EXIT_FAILURE);
	}
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
	testing.test = 0;
	while (i < 2)
	{
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
		waitpid(pid[i], &ret, WEXITED);
		printf("ret_wait-[%d]\n", ret);
	}
	printf("test-[%d]\n", testing.test);
	return (EXIT_SUCCESS);
}
