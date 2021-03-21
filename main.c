/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:03:53 by iharchi           #+#    #+#             */
/*   Updated: 2021/03/21 23:27:39 by iharchi          ###   ########.fr       */
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
    
    a = swap(a);
    push_to(&a, &b);
    push_to(&a, &b);
    push_to(&a, &b);
    a = rotate(a);
    b = rotate(b);
    a = reverse_rotate(a);
    b = reverse_rotate(b);
    a = swap(a);
    push_to(&b, &a);
    push_to(&b, &a);
    push_to(&b, &a);
    printstack(a);
}