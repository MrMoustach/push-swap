/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:06:30 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/25 16:47:53 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int     ft_get_smallest_pos(t_stack stack)
{
    t_stacklist  *tmp;
    int     min;
    int     min_pos;
    int     i;

    if (stack.count == 0)
        return (0);
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


int     get_index(t_stack stack, int value)
{
    t_stacklist *tmp;
    int         ret;

    tmp = stack.list;
    ret = 0;
    while (tmp)
    {
        if (tmp->value > value)
            ret++;
        tmp = tmp->next;
    }
    return (ret);
}

t_stack get_indicies(t_stack stack)
{
    t_stack indicies;
    t_stacklist *tmp;

    tmp = stack.list;
    indicies.list = NULL;
    indicies.count = 0;
    while (tmp)
    {
        indicies = push(indicies, get_index(stack, tmp->value));
        indicies = rotate(indicies);
        tmp = tmp->next;
    }
    return (indicies);
}

int     max_bits(int count)
{
    int max;

    max = 0;
    while ((count >> max) != 0)
        max++;
    return (max);
}

void    ft_n_radix(t_stack *stack, t_stack *stackb, int n)
{
    t_stacklist *tmp;
    int         count;
    t_stack     copy;

    tmp = stack->list;
    count = stack->count;
    copy = copy_stack(*stack);
    while (count--)
    {
        if (((get_index(copy ,top(*stack)) >> n) & 1) == 1)
        {
            push_to(stack, stackb);
            write (1, "pb\n", 3);
        }
        else
        {
            *stack = rotate(*stack);
            write (1, "ra\n", 3);
        }
    }
    while (stackb->count)
    {
        push_to(stackb, stack);
        write (1, "pa\n", 3);
    }
}

t_stack ft_sort_radix(t_stack stack, t_stack stackb)
{
    int     max;
    int     i;

    max = max_bits(stack.count);
    i = 0;
    stackb.count = 0;
    stackb.list = NULL;
    while (i < max)
    {
        ft_n_radix(&stack, &stackb, i);
        i++;
    }
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
        return (ft_sort_radix(stack, stackb));
    return (stack);
}