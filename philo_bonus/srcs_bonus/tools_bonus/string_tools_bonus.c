/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tools_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:44:58 by amarini-          #+#    #+#             */
/*   Updated: 2022/03/30 16:51:04 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	am_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

char	*am_strdup(char *str)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = am_strlen(str);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (i < len)
	{
		res[i] = str[i];
		++i;
	}
	return (res);
}

char	*am_strjoin(char *prefix, char *sufix)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = am_strlen(prefix) + am_strlen(sufix);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (i < len)
	{
		if (prefix[i] == '\0')
			break ;
		res[i] = prefix[i];
		++i;
	}
	while (i < len)
	{
		res[i] = sufix[i - am_strlen(prefix)];
		++i;
	}
	return (res);
}
