/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:07:24 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/25 21:30:34 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int main(int ac, char *av[])
{
	int	flag;
	t_stack	a;
	t_stack	b;
    
	if (ac == 1)
		return (1);
	a = load_stack(av, ac, &flag);
	if (flag)
	{
		write (2, "Error\n", 6);   
		return (1);
	}
    a = ft_sort(a, b);
	return (0);
}