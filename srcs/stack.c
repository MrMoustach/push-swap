/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:59:49 by iharchi           #+#    #+#             */
/*   Updated: 2021/03/19 09:39:44 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void    pop(t_stack stack)
{
    t_stacklist *list;
    t_stacklist *tmp;

    list = stack.list;
    if (list == NULL)
        return ;
    while (list->next != NULL)
    {
        if (list->next->next == NULL)
        {
            tmp = list->next;
            list->next = NULL;
            free(tmp);
            stack.count--;
            return ;
        }
        list = list->next;
    }
}

void    push(t_stack stack, int value)
{
     ft_stackadd_front(&(stack.list), ft_stacknew(value));
     stack.count++;
}

void    push_to(t_stack stack, t_stack stack2)
{
    if (ft_stackisempty(stack))
        return ;
    push(stack2, ft_stacklast(stack.list)->value);
    pop(stack);
}

void    swap(t_stack stack)
{
    int         tmp;
    t_stacklist *secondtolast;
    int         i;

    if (ft_stackisempty(stack))
        return ;
    if (stack.list->next->next == NULL)
        return ;
    tmp = ft_stacklast(stack.list)->value;
    secondtolast = stack.list;
    i = 0;
    while (i++ < stack.list - 1)
        secondtolast = secondtolast->value;
    ft_stacklast(stack.list)->value = secondtolast->value;
    secondtolast->value = tmp;
}

void    rotate(t_stack stack)
{
    int tmp;
    int next;
    t_stacklist *list;

    list = stack.list->next;
    next = stack.list->value;
    while (list != NULL)
    {
        tmp = list->value;
        list->value = next;
        next = tmp;
        list = list->next;
    }
    stack.list->value = next;
}