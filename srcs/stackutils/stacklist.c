/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:52:45 by iharchi           #+#    #+#             */
/*   Updated: 2021/05/25 10:10:54 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

t_stacklist	*ft_stacknew(int content)
{
	t_stacklist *ret;

	if (!(ret = (t_stacklist *)malloc(sizeof(t_stacklist))))
		return (NULL);
	ret->value = content;
	ret->next = NULL;
	return (ret);
}

void	ft_stackadd_back(t_stacklist **alst, t_stacklist *new)
{
	t_stacklist *tmp;

	if (!alst)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_stackadd_front(t_stacklist **alst, t_stacklist *new)
{
	if (new )
	{
		if (*alst != NULL)
			new->next = *alst;
		else
			new->next = NULL;
		*alst = new;
	}
}

void	ft_stackclear(t_stacklist **lst)
{
	t_stacklist *tmp;

	if (lst)
	{
		tmp = *lst;
		while (tmp != NULL)
		{
			*lst = tmp->next;
			ft_stackdelone(tmp);
			tmp = *lst;
		}
		lst = NULL;
	}
}

void	ft_stackdelone(t_stacklist *lst)
{
	t_stacklist *tmp;

	if (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

t_stacklist	*ft_stacklast(t_stacklist *lst)
{
	t_stacklist *tmp;

	tmp = lst;
	if (tmp == NULL)
		return (tmp);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int			ft_stackisempty(t_stack stack)
{
	return (stack.list == NULL);
}
int			ft_is_stack_sorted(t_stack stack)
{
	t_stacklist	*tmp;
	
	tmp = stack.list;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
