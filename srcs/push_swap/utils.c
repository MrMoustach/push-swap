/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:06:30 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/02 14:07:31 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

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

// TODO : needs to be smarter
t_stack ft_sort_three(t_stack stack)
{
    int min_pos;
    t_stack tmp;

    min_pos = ft_get_smallest_pos(stack);
    tmp = copy_stack(stack);
    if (min_pos == 0)
    {
        stack = swap(stack);
        write (1, "sa\n", 3);
        stack = rotate(stack);
        write (1, "ra\n", 4);
    }
    else if (min_pos == 1)
    {
        tmp = swap(tmp);
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
        tmp = reverse_rotate(tmp);
        if (ft_is_stack_sorted(tmp))
        {
            
            stack = tmp;
            write (1, "rra\n", 4);
        }
        else
        {
            stack = swap(stack);
            write (1, "sa\n", 3);
            stack = reverse_rotate(stack);
            write (1, "rra\n", 4);
        }
    }
    return (stack);
}

t_stack put_lowest_top(t_stack stack)
{
    int min_pos;

    min_pos = ft_get_smallest_pos(stack);
    while (min_pos != 0)
    {
        if (min_pos <= 2)
        {
            stack = rotate(stack);
            write (1, "ra\n", 3);
        }
        else
        {
            stack = reverse_rotate(stack);
            write (1, "rra\n", 4);
        }
        min_pos = ft_get_smallest_pos(stack);
    }
    return (stack);
}
// TODO : change to highest 2 to b
t_stack ft_sort_five(t_stack stack, t_stack stackb)
{
    stackb.count = 0;
    while (stack.count != 3)
    {
        stack = put_lowest_top(stack);
        push_to(&stack, &stackb);
        write (1, "pb\n", 3);
    }
    stack = ft_sort_three(stack);
    while (stack.count != 5 && stackb.count > 0)
    {
        push_to(&stackb, &stack);
        write (1, "pa\n", 3);
    }
    return (stack);
}
// TODO : useless
t_stack ft_sort_all(t_stack stack, t_stack stackb)
{
    stackb.count = 0;
    while (stack.count != 3)
    {
        stack = put_lowest_top(stack);
        push_to(&stack, &stackb);
        write (1, "pb\n", 3);
    }
    stack = ft_sort_three(stack);
    while (stackb.count != 0)
    {
        push_to(&stackb, &stack);
        write (1, "pa\n", 3);
    }
    return (stack);
}

int     ft_get_median(t_stack stack, int min, int max)
{
    int average;
    t_stacklist *tmp;
    
    average = get_average(stack, max, min);
    tmp = stack.list;
    while (tmp)
    {
        if (tmp->value == average)
            return (tmp->value);
        if (tmp->value < min && tmp->value > average)
            min = tmp->value;
        if (tmp->value > max && tmp->value < average)
            max = tmp->value;
        tmp = tmp->next;
    }
    if (average - min < max - average)
        return (min);
    else
        return (max);
}

int     ft_under_median(t_stack stack, int median, int min)
{
    t_stacklist *tmp;
    int         top;
    int         bot;
    int         i;
    int         flag;

    tmp = stack.list;
    top = 0;
    bot = 0;
    i = 0;
    flag = 0;
    while (tmp)
    {
        if (tmp->value <= median && tmp->value >= min)
        {
            top = i;
            flag = 1;
            break ;
        }
        i++;
        tmp = tmp->next;
    }
    i = 0;
    tmp = stack.list;
    while (tmp)
    {
        if (tmp->value <= median && tmp->value >= min)
            bot = i;
        i++;
        tmp = tmp->next;
    }
    if (flag)
    {
        if (top < stack.count - bot)
            return (top);
        else
            return (bot);
    }
    return (-1);
}

int     ft_above_median(t_stack stack, int median, int max)
{
    t_stacklist *tmp;
    int         top;
    int         bot;
    int         i;
    int         flag;

    tmp = stack.list;
    top = 0;
    bot = 0;
    i = 0;
    flag = 0;
    while (tmp)
    {
        if (tmp->value >= median && tmp->value >= max)
        {
            flag = 1;
            break ;
        }
        top++;
        tmp = tmp->next;
    }
    tmp = stack.list;
    while (tmp)
    {
        if (tmp->value <= median && tmp->value >= max)
            bot = i;
        i++;
        tmp = tmp->next;
    }
    if (flag)
    {
        if (top < (stack.count - bot) - 1)
            return (top);
        else
            return (bot);
    }
    return (-1);
}

t_stack ft_get_to_top(t_stack stack, int pos, char a)
{
    if (stack.count <= 1)
        return (stack);
    if (stack.count / 2 > pos)
    {
        while(pos--)
        {
            stack = rotate(stack);
            if (a == 'a')
                write (1, "ra\n", 3);
            else
                write (1, "rb\n", 3);
        }
    }
    else
    {
        while (pos++ < stack.count)
        {
            stack = reverse_rotate(stack);
            if (a == 'a')
                write (1, "rra\n", 4);
            else
                write (1, "rrb\n", 4);
        }
    }
    return (stack);
}

t_stack ft_sort_part(t_stack stack, t_stack stackb, int (*part)(t_stack, int, int), int median, int limit)
{
    int pos;
    int top;
    
    pos = part(stack, median, limit);
    while (pos >= 0)
    {
        stack = ft_get_to_top(stack, pos, 'a');
        write(1, "pb\n", 3);
        if (stackb.count > 0)
            top = stackb.list->value;
        push_to(&stack, &stackb);
        if (top < stackb.list->value && stackb.count > 1)
        {
            stackb = swap(stackb);
            write (1, "sb\n", 3);
        }
        pos = part(stack, median, limit);
    }
    while (stackb.count)
    {
        pos = ft_get_smallest_pos(stackb);
        stackb = ft_get_to_top(stackb, pos, 'b');
        push_to(&stackb, &stack);
        write(1, "pa\n", 3);
        stack = rotate(stack);
        write(1, "ra\n", 3);
    }
    return (stack);
}

t_stack ft_sort_all_median(t_stack stack, t_stack stackb)
{
    t_stacklist *tmp;
    int         median[10];
    int i;

    tmp = stack.list;
    stackb.count = 0;
    median[1] = ft_get_median(stack, get_max(stack), get_min(stack));
    median[0] = ft_get_median(stack, median[1], get_min(stack));
    median[2] = ft_get_median(stack, get_max(stack), median[1]);
    median[3] = ft_get_median(stack, median[1], median[0]);
    median[4] = ft_get_median(stack, median[2], median[1]);
    
    // idk mate kill  me pls
    // min - 0                                        smaller than  bigger than
    // stack = ft_sort_part(stack, stackb, ft_under_median, median[0],get_min(stack));
    // stack = ft_sort_part(stack, stackb, ft_under_median, median[1],median[3]);
    // stack = ft_sort_part(stack, stackb, ft_under_median, median[4],median[1]);
    // stack = ft_sort_part(stack, stackb, ft_under_median, median[2],median[4]);
    // stack = ft_sort_part(stack, stackb, ft_under_median, median[3],median[0]);
    // stack = ft_sort_part(stack, stackb, ft_under_median, get_max(stack), median[2]);

    stack = ft_sort_part(stack, stackb, ft_under_median,median[2], median[1]);
    stack = ft_sort_part(stack, stackb, ft_under_median,median[1], median[0]);
    stack = ft_sort_part(stack, stackb, ft_under_median,median[0], get_min(stack));
    stack = ft_sort_part(stack, stackb, ft_under_median,get_max(stack), median[2]);
    
    // stack = ft_sort_part(stack, stackb, ft_under_median, median[0],get_min(stack));
    // stack = ft_sort_part(stack, stackb, ft_above_median, median[0],median[1]);
    // stack = ft_sort_part(stack, stackb, ft_under_median, median[2],median[1]);
    // stack = ft_sort_part(stack, stackb, ft_above_median, median[2],get_max(stack));
    // 0 - 3
    // stack = ft_sort_part(stack, stackb, ft_above_median, median[0], median[3]);
    // // 3 - 1
    // // stack = ft_sort_part(stack, stackb, ft_under_median, median[3],median[0]);
    // // 1 - 4
    // stack = ft_sort_part(stack, stackb, ft_above_median, median[3], median[1]);
    // // 4 - 2
    // stack = ft_sort_part(stack, stackb, ft_under_median, median[4],median[1]);
    
    // stack = ft_sort_part(stack, stackb, ft_above_median, median[4],median[2]);
    // // 2 - max
    // stack = ft_sort_part(stack, stackb, ft_above_median, median[2], get_max(stack));

    // stack = ft_sort_part(stack, stackb, ft_under_median, median[2],median[1]);
    // stack = ft_sort_part(stack, stackb, ft_above_median, median[2], get_max(stack));
    // printf("medians : %d %d %d %d %d", median[0], median[3], median[1], median[4], median[2]);
    printf("medians : %d %d %d", median[0], median[1], median[2]);
    return (stack);
}

t_stack ft_sort(t_stack stack, t_stack stackb)
{
    if (ft_is_stack_sorted(stack))
        return (stack);
    if(stack.count == 2)
        write(1, "sa\n", 3);
    else if (stack.count <= 5)
        return (ft_sort_five(stack, stackb));
    else
        return (ft_sort_all_median(stack, stackb));
    return (stack);
}