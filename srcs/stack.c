/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:59:49 by iharchi           #+#    #+#             */
/*   Updated: 2021/03/20 14:46:20 by iharchi          ###   ########.fr       */
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
    tmp = stack.list->next;
    free(stack.list);
    stack.list = tmp;
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
    push(stack2, stack.list->value);
    pop(stack);
}

void    swap(t_stack stack)
{
    int         tmp;
    t_stacklist *second;
    int         i;

    if (ft_stackisempty(stack))
        return ;
    if (stack.list->next->next == NULL)
        return ;
    tmp = stack.list->value;
    second = stack.list->next;
    stack.list->value = second->value;
    second->value = tmp;
}

void    rotate(t_stack stack)
{
   t_stacklist *tmp;

   tmp = stack.list;
   tmp->next = NULL;
   stack.list = stack.list->next;
   ft_stacklast(stack.list)->next = tmp;
}