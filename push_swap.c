/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:07:24 by iharchi           #+#    #+#             */
/*   Updated: 2021/05/28 12:36:31 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int main(int ac, char *av[])
{
	int	flag;
	t_stack	a;
	t_stack	b;
    
	if (ac == 1)
	{
		write (1, "Error\n", 6);   
		return (0);
	}
	a = load_stack(av, ac, &flag);
	// printstacks(a, b);
    a = ft_sort(a, b);
	// printstacks(a, b);
}