/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:28:57 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/25 21:26:14 by iharchi          ###   ########.fr       */
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

int test_duplicates(char **av)
{
    int i;
    int j;
    int len;
    
    i = 0;
    while (av[i])
    {
        j = 0;
        while (av[j])
        {
            len = ft_strlen(av[j]);
            if (ft_strlen(av[i]) > len)
                len = ft_strlen(av[i]);
            if (!ft_strncmp(av[i], av[j], len) && i != j)
                return 1;
            j++;
        }
        i++;
    }
    return (0);
}

t_stack load_stack(char *av[],int ac, int *flag)
{
    t_stack a;
    int     i;

    a.list = NULL;
    *flag = 0;
    i = ac;
    *flag = test_duplicates(av);
    while (--i > 0 && !*flag)
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