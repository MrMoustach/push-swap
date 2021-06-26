/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:33:50 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/26 18:38:40 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	get_index(t_stack stack, int value)
{
	t_stacklist	*tmp;
	int			ret;

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

int	max_bits(int count)
{
	int	max;

	max = 0;
	while ((count >> max) != 0)
		max++;
	return (max);
}

t_stack	put_lowest_top(t_stack stack)
{
	int	min_pos;

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

int	ft_get_smallest_pos(t_stack stack)
{
	t_stacklist	*tmp;
	int			min;
	int			min_pos;
	int			i;

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
	return (min_pos);
}
