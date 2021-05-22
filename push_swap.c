/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:07:24 by iharchi           #+#    #+#             */
/*   Updated: 2021/05/22 16:57:35 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

t_stack load_stack(char *av[], int *flag)
{
    t_stack a;
    int     i;

    a.list = NULL;
    *flag = 0;
    i = 1;
    while (av[i])
    {
        if (!ft_is_number(av[i]))
        {
            *flag = 1;
            break ;
        }
        a = push(a, ft_atoi(av[i]));
        i++;
    }
    a.count = --i;
    return (a);
}

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
	a = load_stack(av, &flag);
	printstacks(a, b);
    a = ft_sort(a);
	printstacks(a, b);
}