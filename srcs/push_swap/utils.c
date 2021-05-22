/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:06:30 by iharchi           #+#    #+#             */
/*   Updated: 2021/05/22 16:58:01 by iharchi          ###   ########.fr       */
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

int     ft_get_smallest_pos(t_stack stack)
{
    t_stacklist  *tmp;
    int     min;
    int     min_pos;
    int     i;

    tmp = stack.list;
    min = stack.list->value;
    min_pos = 0;
    i = 0;
    while (tmp)
    {
        if (min > tmp->value)
        {
            min = tmp->value;
            min_pos = i;
        }
        i++;
        tmp = tmp->next;
    }
    return min_pos;
}

t_stack ft_sort_three(t_stack stack)
{
    int min_pos;
    t_stack tmp;

    min_pos = ft_get_smallest_pos(stack);
    if (min_pos == 0)
    {
        stack = swap(stack);
        write (1, "sa\n", 3);
        stack = rotate(stack);
        write (1, "ra\n", 4);
    }
    else if (min_pos == 1)
    {
        tmp = swap(stack);
        if (ft_is_stack_sorted(tmp))
        {
            stack = tmp;
            write (1, "sa\n", 3);

        }
        else
        {
            stack = rotate(stack);
            write (1, "ra\n", 3);
        }
    }
    else
    {
        tmp = reverse_rotate(stack);
        if (ft_is_stack_sorted(tmp))
        {
            stack = tmp;
            write (1, "rra\n", 4);
        }
        else
        {
            stack = reverse_rotate(stack);
            write (1, "rra\n", 4);
        }
    }
    return (stack);
}

t_stack ft_sort(t_stack stack)
{
    if (ft_is_stack_sorted(stack))
        return (stack);
    if (stack.count <= 3)
    {
        return (ft_sort_three(stack));
    }
    return (stack);
}