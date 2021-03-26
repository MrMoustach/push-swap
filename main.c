/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:03:53 by iharchi           #+#    #+#             */
/*   Updated: 2021/03/25 12:42:44 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int main(int ac, char *av[])
{
    int array[] = {8,5,6,3,1,2,0};
    t_stack a;
    t_stack b;
    int i;

    i = 0;
    a.list = NULL;
    while (array[i])
    {
        a = push(a, array[i]);
        i++;
    }
    
    b.list = NULL;
    while (!ft_stackisempty(a))
    {
        i = a.list->value;
        a = pop(a);
        while (!ft_stackisempty(b) && b.list->value < i)
            push_to(&b, &a);
        b = push(b, i);
    }
    printstack(b);
}