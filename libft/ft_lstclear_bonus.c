/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:39:08 by iharchi           #+#    #+#             */
/*   Updated: 2019/10/18 06:02:48 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (lst && del)
	{
		tmp = *lst;
		while (tmp != NULL)
		{
			*lst = tmp->next;
			ft_lstdelone(tmp, del);
			tmp = *lst;
		}
		lst = NULL;
	}
}
