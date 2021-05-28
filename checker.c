/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:21:06 by iharchi           #+#    #+#             */
/*   Updated: 2021/05/28 16:17:11 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int main(int ac, char *av[])
{
    t_stack a;
    t_stack b;
    int flag;
    char    *line;
    int     n;
    
    if (ac < 2)
    {
        write (2, "error\nPlease include a stack in the args", 41);
        return (-1);
    }
    a = load_stack(av, ac, &flag);
    line = NULL;
    int fd = open("test", O_RDONLY);
    b.count = 0;
    while (1)
    {
        printstacks(a, b);
        get_next_line(0, &line);
        if (!ft_strncmp(line, "sa", 3))
            a = swap(a);
        if (!ft_strncmp(line, "sb", 3))
            b = swap(b);
        if (!ft_strncmp(line, "ss", 3))
        {
            a = swap(a);
            b = swap(b);
        }
        if (!ft_strncmp(line, "pa", 3))
            push_to(&b, &a);
        if (!ft_strncmp(line, "pb", 3))
            push_to(&a, &b);
        if (!ft_strncmp(line, "ra", 3))
            a = rotate(a);
        if (!ft_strncmp(line, "rb", 3))
            b = rotate(b);
        if (!ft_strncmp(line, "rr", 3))
        {
            a = rotate(a);
            b = rotate(b);
        }
        if (!ft_strncmp(line, "rra", 4))
            a = reverse_rotate(a);
        if (!ft_strncmp(line, "rrb", 4))
            b = reverse_rotate(b);
        if (!ft_strncmp(line, "rrr", 4))
        {
            a = reverse_rotate(a);
            b = reverse_rotate(b);
        }
        if (*line == '\0')
            break ;
    }
    if (ft_is_stack_sorted(a) && b.count == 0)
        printf("OK\n");
    else
        printf("KO\n");
}