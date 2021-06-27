/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:36:05 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/27 14:40:34 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	ft_sort_three_helper(t_stack *stack, t_stack *tmp)
{
	*tmp = swap(*tmp);
	if (ft_is_stack_sorted(*tmp))
	{
		*stack = swap(*stack);
		write (1, "sa\n", 3);
	}
	else
	{
		*stack = rotate(*stack);
		write (1, "ra\n", 3);
	}
}

void	ft_sort_three_helper2(t_stack *stack, t_stack *tmp)
{
	*tmp = reverse_rotate(*tmp);
	if (ft_is_stack_sorted(*tmp))
	{
		*stack = reverse_rotate(*stack);
		write (1, "rra\n", 4);
	}
	else
	{
		*stack = swap(*stack);
		write (1, "sa\n", 3);
		*stack = reverse_rotate(*stack);
		write (1, "rra\n", 4);
	}
}
