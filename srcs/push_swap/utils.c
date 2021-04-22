/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:06:30 by iharchi           #+#    #+#             */
/*   Updated: 2021/04/22 14:10:10 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int ft_is_number(char *s)
{
    int i;
    if (!s)
        return (0);
    i = 0;
    while (s[i])
    {
        if (!ft_isdigit(s[i]))
            return (0);
            i++;
    }
    return (1);
}