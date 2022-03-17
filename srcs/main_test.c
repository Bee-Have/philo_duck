/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:59:31 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/17 02:58:16 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// long	get_current_time(void)
// {
// 	struct timeval	time;
// 	long			res;
	
// 	gettimeofday(&time, NULL);
// 	res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
// 	return (res);
// }

void	*my_thread(void *test)
{
	int	*tmp;

	tmp = (int *)test;
	print_action_time(*tmp, MSG_SLEEP);
	printf("Hello from thread :D\n");
	return (NULL);
}

int	main(void)
{
	pthread_t	tid;
	int			nbr_philo;
	int			i;

	nbr_philo = 2;
	i = 0;
	while (i < nbr_philo)
	{
		int	tmp = i;
		pthread_create(&tid, NULL, my_thread, &tmp);
		++i;
	}
	i = 0;
	while (i < nbr_philo)
	{
		pthread_join(tid, NULL);
		++i;
	}
}