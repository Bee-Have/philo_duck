/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 02:00:06 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/17 04:56:33 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	calc_len(long nbr)
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

char	*am_ltoa(long nbr)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = calc_len(nbr);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (i < len)
	{
		res[len - i - 1] = (nbr % 10) + '0';
		nbr /= 10;
		++i;
	}
	return (res);
}

long	am_atol(char *str)
{
	long	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		res = (res * 10) + (str[i] - '0');
		++i;
	}
	return (res);
}