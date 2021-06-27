/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:06:30 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/27 14:54:13 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

t_stack	ft_sort_three(t_stack stack)
{
	int		min_pos;
	t_stack	tmp;

	min_pos = ft_get_smallest_pos(stack);
	tmp = copy_stack(stack);
	if (min_pos == 0)
	{
		stack = swap(stack);
		write (1, "sa\n", 3);
		if (!ft_is_stack_sorted(stack))
		{
			stack = rotate(stack);
			write (1, "ra\n", 3);
		}
	}
	else if (min_pos == 1)
		ft_sort_three_helper(&stack, &tmp);
	else
		ft_sort_three_helper2(&stack, &tmp);
	free_stack(&tmp);
	return (stack);
}

t_stack	ft_sort_five(t_stack stack, t_stack stackb)
{
	stackb.count = 0;
	while (stack.count != 3)
	{
		stack = put_lowest_top(stack);
		push_to(&stack, &stackb);
		write (1, "pb\n", 3);
	}
	if (!ft_is_stack_sorted(stack))
		stack = ft_sort_three(stack);
	while (stack.count != 5 && stackb.count > 0)
	{
		push_to(&stackb, &stack);
		write (1, "pa\n", 3);
	}
	return (stack);
}

void	ft_n_radix(t_stack *stack, t_stack *stackb, int n)
{
	int			count;
	t_stack		copy;

	count = stack->count;
	copy = copy_stack(*stack);
	while (count--)
	{
		if (((get_index(copy, top(*stack)) >> n) & 1) == 1)
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
	free_stack(&copy);
}

t_stack	ft_sort_radix(t_stack stack, t_stack stackb)
{
	int		max;
	int		i;

	max = max_bits(stack.count);
	i = 0;
	stackb.count = 0;
	stackb.list = NULL;
	while (i < max)
		ft_n_radix(&stack, &stackb, i++);
	return (stack);
}

t_stack	ft_sort(t_stack stack, t_stack stackb)
{
	if (ft_is_stack_sorted(stack))
		return (stack);
	if (stack.count == 2)
		write(1, "sa\n", 3);
	else if (stack.count <= 5)
		return (ft_sort_five(stack, stackb));
	else
		return (ft_sort_radix(stack, stackb));
	return (stack);
}
