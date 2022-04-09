/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 02:00:06 by amarini-          #+#    #+#             */
/*   Updated: 2022/04/09 02:12:53 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	calc_len(long nbr)
{
	int	len;

	len = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		++len;
	}
	return (len);
}

long	am_atol(char *str)
{
	long	res;
	int		i;

	i = 0;
	if (am_strlen(str) > 10)
		return (-1);
	if (str[0] == '-')
		i = 1;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = (res * 10) + (str[i] - '0');
		++i;
	}
	if (str[0] == '-')
		res *= -1;
	return (res);
}
