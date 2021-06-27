/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:59:49 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/27 14:39:39 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

t_stack	pop(t_stack stack)
{
	t_stacklist	*list;
	t_stacklist	*tmp;

	list = stack.list;
	if (list == NULL)
		return (stack);
	tmp = stack.list->next;
	free(stack.list);
	stack.list = tmp;
	stack.count--;
	return (stack);
}

t_stack	push(t_stack stack, int value)
{
	 ft_stackadd_front(&(stack.list), ft_stacknew(value));
	 stack.count++;
	 return (stack);
}

t_stack	swap(t_stack stack)
{
	int			tmp;
	t_stacklist	*second;

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

t_stack	rotate(t_stack stack)
{
	t_stacklist	*tmp;

	if (stack.list == NULL || stack.count <= 1)
		return (stack);
	tmp = stack.list;
	stack.list = stack.list->next;
	ft_stacklast(stack.list)->next = tmp;
	tmp->next = NULL;
	return (stack);
}

t_stack	reverse_rotate(t_stack stack)
{
	t_stacklist	*tmp;
	t_stacklist	*second_to_last;

	if (stack.count < 2)
		return (stack);
	second_to_last = stack.list;
	while (second_to_last->next->next)
		second_to_last = second_to_last->next;
	tmp = ft_stacklast(stack.list);
	second_to_last->next = NULL;
	ft_stackadd_front(&(stack.list), tmp);
	return (stack);
}
