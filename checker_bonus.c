/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:21:06 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/27 14:53:54 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

static int	select_action_helper(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "rra", 4))
		*a = reverse_rotate(*a);
	else if (!ft_strncmp(line, "rrb", 4))
		*b = reverse_rotate(*b);
	else if (!ft_strncmp(line, "rrr", 4))
	{
		*a = reverse_rotate(*a);
		*b = reverse_rotate(*b);
	}
	else if (*line == '\0')
		return (2);
	else
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	return (0);
}

static int	select_action(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa", 3))
		*a = swap(*a);
	else if (!ft_strncmp(line, "sb", 3))
		*b = swap(*b);
	else if (!ft_strncmp(line, "ss", 3))
	{
		*a = swap(*a);
		*b = swap(*b);
	}
	else if (!ft_strncmp(line, "pa", 3))
		push_to(b, a);
	else if (!ft_strncmp(line, "pb", 3))
		push_to(a, b);
	else if (!ft_strncmp(line, "ra", 3))
		*a = rotate(*a);
	else if (!ft_strncmp(line, "rb", 3))
		*b = rotate(*b);
	else if (!ft_strncmp(line, "rr", 3))
	{
		*a = rotate(*a);
		*b = rotate(*b);
	}
	else
		return (select_action_helper(line, a, b));
	return (0);
}

int	is_sorted(t_stack a, t_stack b)
{
	if (ft_is_stack_sorted(a) && b.count == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;
	int		flag;
	char	*line;

	if (ac < 2)
		return (write (2, "error\nPlease include a stack in the args", 41) - 40);
	a = load_stack(av, ac, &flag);
	line = NULL;
	b.count = 0;
	if (flag != 0)
	{
		write (2, "error\n", 7);
		return (1);
	}
	while (1)
	{
		get_next_line(0, &line);
		flag = select_action(line, &a, &b);
		if (flag == 2)
			break ;
	}
	return (is_sorted(a, b));
}
