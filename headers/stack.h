/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:35:47 by iharchi           #+#    #+#             */
/*   Updated: 2021/03/21 23:23:32 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "push_swap.h"

typedef struct  s_stacklist
{
    int                 value;
    struct s_stacklist	*next;
}               t_stacklist;

typedef struct  s_stack
{
    t_stacklist      *list;
    int         count;
}               t_stack;

t_stacklist			*ft_stacknew(int  content);
void			    ft_stackadd_front(t_stacklist **alst, t_stacklist *new);
int				    ft_stacksize(t_stacklist *lst);
t_stacklist			*ft_stacklast(t_stacklist *lst);
void			    ft_stackadd_back(t_stacklist **alst, t_stacklist *new);
void			    ft_stackdelone(t_stacklist *lst);
void			    ft_lstacklear(t_stacklist **lst);
int			        ft_stackisempty(t_stack stack);
t_stack                pop(t_stack stack);
t_stack             push(t_stack stack, int value);
void                push_to(t_stack *stack, t_stack *stack2);
t_stack                swap(t_stack stack);
t_stack                rotate(t_stack stack);
t_stack     reverse_rotate(t_stack stack);
#endif