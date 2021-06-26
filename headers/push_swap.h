/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:36:40 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/26 20:14:21 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "stack.h"
# define MAX_INT 2147483647
# define MIN_INT -2147483648

int			ft_is_number(char *s);
int			ft_get_smallest_pos(t_stack stack);
t_stack		ft_sort(t_stack stack, t_stack stackb);
t_stack		load_stack(char *av[], int ac, int *flag);
long long	ft_atol(const char *str);
void		free_stack(t_stack *stack);
void		ft_sort_three_helper(t_stack *stack, t_stack *tmp);
void		ft_sort_three_helper2(t_stack *stack, t_stack *tmp);
int			get_index(t_stack stack, int value);
int			max_bits(int count);
t_stack		put_lowest_top(t_stack stack);
int			ft_get_smallest_pos(t_stack stack);
#endif