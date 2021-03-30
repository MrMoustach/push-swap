/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:21:06 by iharchi           #+#    #+#             */
/*   Updated: 2021/03/29 11:30:17 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int main(int ac, char *av[])
{
    int i;
    t_stack a;
    t_stack b;
    int flag;
    if (ac < 2)
    {
        write (2, "error\nPlease include a stack in the args", 41);
        return (-1);
    }
    i = 0;
    a.list = NULL;
    b.list = NULL;
    flag = 0;
    while (av[i])
    {
        if (ft_is_number(av[i]))
        {
            flag = 1;
            break ;
        }
        a = push(a, ft_atoi(av[i]));
        i++;
    }
    printstack(a);
}