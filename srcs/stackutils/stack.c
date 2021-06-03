/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:59:49 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/03 12:39:41 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

t_stack    pop(t_stack stack)
{
    t_stacklist *list;
    t_stacklist *tmp;

    list = stack.list;
    if (list == NULL)
        return (stack);
    tmp = stack.list->next;
    free(stack.list);
    stack.list = tmp;
    stack.count--;
    return (stack);
}

t_stack    push(t_stack stack, int value)
{
    // Problems
     ft_stackadd_front(&(stack.list), ft_stacknew(value));
     stack.count++;
     return (stack);
}

void    push_to(t_stack *stack, t_stack *stack2)
{
    if (ft_stackisempty(*stack))
        return ;
    *stack2 = push(*stack2, stack->list->value);
    *stack = pop(*stack);
}

t_stack    swap(t_stack stack)
{
    int         tmp;
    t_stacklist *second;
    int         i;

    if (ft_stackisempty(stack))
        return (stack);
    if (stack.list->next->next == NULL)
        return (stack);
    tmp = stack.list->value;
    second = stack.list->next;
    stack.list->value = second->value;
    second->value = tmp;
    return (stack);
}

t_stack    rotate(t_stack stack)
{
   t_stacklist *tmp;

   if (stack.list == NULL || stack.count <= 1)
        return (stack);
   tmp = stack.list;
   stack.list = stack.list->next;
   ft_stacklast(stack.list)->next = tmp;
   tmp->next = NULL;
   return (stack);
}

t_stack     reverse_rotate(t_stack stack)
{
    t_stacklist *tmp;
    t_stacklist *second_to_last;

    second_to_last = stack.list;
    while (second_to_last->next->next)
        second_to_last = second_to_last->next;
    tmp = ft_stacklast(stack.list);
    second_to_last->next = NULL;
    ft_stackadd_front(&(stack.list), tmp);
    return (stack);
}

void    printstack(t_stack stack)
{
    t_stacklist *list;

    list = stack.list;
    while (list)
    {
        printf("%d\n", list->value);
        list = list->next;
    }
}

void    printstacks(t_stack a, t_stack b)
{
    t_stacklist *list1;
    t_stacklist *list2;
    int         last;

    list1 = a.list;
    list2 = b.list;
    last = list1->value;
    while (list1 || list2)
    {
        if (list1)
        {
            if (last > list1->value)
                printf("%d ", list1->value);
            else
                printf("%d ", list1->value);
            list1 = list1->next;
            if (list1)
                last = list1->value;
        }
        else
            printf("  ");
        if (list2)
        {   
            printf("%d ", list2->value);
            list2 = list2->next;
        }
        else
            printf("  ");
        printf("\n");
    }
    printf("-------\na b\n");
}

t_stack     copy_stack(t_stack stack)
{
    t_stacklist *tmp;
    t_stack ret;

    tmp = stack.list;
    ret.list = NULL;
    while (tmp)
    {
        ft_stackadd_back(&ret.list, ft_stacknew(tmp->value));
        tmp = tmp->next;
    }
    return (ret);
}

int     get_min(t_stack stack)
{
    int         min;
    t_stacklist *tmp;

    min = stack.list->value;
    tmp = stack.list;
    while (tmp)
    {
        if (tmp->value < min)
            min = tmp->value;
        tmp = tmp->next;
    }
    return (min);
}

int     get_max(t_stack stack)
{
    int     max;
    t_stacklist *tmp;

    max = stack.list->value;
    tmp = stack.list;
    while (tmp)
    {
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
    return (max);
}

int     get_average(t_stack stack, int min, int max)
{
    int     average;
    t_stacklist *tmp;
    int         count;

    tmp = stack.list;
    count = 0;
    average = 0;
    while (tmp)
    {
        if (tmp->value >= min && tmp->value <= max)
        {
            count++;
            average += tmp->value;
        }
        tmp = tmp->next;
    }
    average = (int)((float)average / (float) count);
    return (average);
}