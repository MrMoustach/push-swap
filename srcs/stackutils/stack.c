/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:59:49 by iharchi           #+#    #+#             */
/*   Updated: 2021/03/30 11:22:21 by iharchi          ###   ########.fr       */
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

   if (stack.list == NULL)
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

    list1 = a.list;
    list2 = b.list;
    while (list1 || list2)
    {
        if (list1)
        {   
            printf("%d ", list1->value);
            list1 = list1->next;
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