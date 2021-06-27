/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:56:32 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/27 14:40:51 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

t_stack	copy_stack(t_stack stack)
{
	t_stacklist	*tmp;
	t_stack		ret;

	tmp = stack.list;
	ret.list = NULL;
	while (tmp)
	{
		ft_stackadd_back(&ret.list, ft_stacknew(tmp->value));
		tmp = tmp->next;
	}
	ret.count = stack.count;
	return (ret);
}

int	top(t_stack stack)
{
	return (stack.list->value);
}

void	free_stack(t_stack *stack)
{
	t_stacklist	*tmp;

	while (stack->list)
	{
		tmp = stack->list->next;
		free(stack->list);
		stack->list = tmp;
	}
}

void	push_to(t_stack *stack, t_stack *stack2)
{
	if (ft_stackisempty(*stack))
		return ;
	*stack2 = push(*stack2, stack->list->value);
	*stack = pop(*stack);
}
