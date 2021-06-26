/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:52:45 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/26 20:00:40 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	ft_stackadd_back(t_stacklist **alst, t_stacklist *new)
{
	t_stacklist	*tmp;

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
	if (new)
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
	t_stacklist	*tmp;

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
	t_stacklist	*tmp;

	if (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

t_stacklist	*ft_stacklast(t_stacklist *lst)
{
	t_stacklist	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (tmp);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
