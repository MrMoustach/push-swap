/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:36:40 by iharchi           #+#    #+#             */
/*   Updated: 2021/05/22 16:57:16 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
#include "../gnl/get_next_line.h"
# include "stack.h"
# include "dev.h"

int ft_is_number(char *s);
int ft_get_smallest_pos(t_stack stack);
t_stack ft_sort(t_stack stack);
#endif