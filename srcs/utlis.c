/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:28:57 by iharchi           #+#    #+#             */
/*   Updated: 2021/05/28 12:30:03 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int ft_is_number(char *s)
{
    int i;

    if (!s)
        return (0);
    i = 0;
    while (s[i] && (s[i] == ' ' || s[i] == '+' || s[i] == '-'))
    {
        if (ft_isdigit(s[i]))
            break ;
        i++;
        if (s[i] == '+' || s[i] == '-')
            break ;
    }
    while (s[i])
    {
        if (!ft_isdigit(s[i]))
            return (0);
            i++;
    }
    return (1);
}

t_stack load_stack(char *av[],int ac, int *flag)
{
    t_stack a;
    int     i;

    a.list = NULL;
    *flag = 0;
    i = ac;
    while (av[--i] > 0)
    {
        if (!ft_is_number(av[i]))
        {
            *flag = 1;
            break ;
        }
        a = push(a, ft_atoi(av[i]));
    }
    a.count = ac - 1;
    return (a);
}