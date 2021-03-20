/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:57:05 by iharchi           #+#    #+#             */
/*   Updated: 2019/10/19 21:20:47 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *tmp;
	t_list *newtmp;

	new = NULL;
	if (lst && f)
	{
		tmp = lst;
		new = ft_lstnew(f(tmp->content));
		tmp = tmp->next;
		while (tmp != NULL)
		{
			if (!(newtmp = ft_lstnew(f(tmp->content))))
			{
				ft_lstclear(&new, del);
				new = NULL;
				break ;
			}
			ft_lstadd_back(&new, newtmp);
			tmp = tmp->next;
		}
	}
	return (new);
}
