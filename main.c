/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:03:53 by iharchi           #+#    #+#             */
/*   Updated: 2021/03/21 20:33:02 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int main(int ac, char *av[])
{
    int array[] = {5,2,8,9,3,4,7,0};
    t_stack a;
    int i;

    i = 0;
    a.list = NULL;
    while (array[i])
    {
        a = push(a, array[i]);
        i++;
    }
    printstack(a);
    printf("---\n");
    a = rotate(a);
    printstack(a);
    printf("---\n");
    a = swap(a);
    printstack(a);
}