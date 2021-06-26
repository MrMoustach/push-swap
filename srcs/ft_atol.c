/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:23:56 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/26 17:43:48 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	ft_isws(char c)
{
	if (c == '\n' || c == '\f' || c == ' '
		|| c == '\r' || c == '\v' || c == '\t')
		return (1);
	return (0);
}

long long	ft_atol(const char *str)
{
	int				i;
	long long		n;
	int				signe;

	n = 0;
	i = 0;
	signe = 1;
	while (ft_isws(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			signe = -1;
	}
	while (str[i] >= '0' && (str[i] <= '9') && str[i] != '\0')
	{
		n = (n * 10) + (str[i++] - '0');
	}
	return (n * signe);
}
