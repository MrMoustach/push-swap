/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklist_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:59:52 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/26 20:01:06 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	ft_stackisempty(t_stack stack)
{
	return (stack.list == NULL);
}

int	ft_is_stack_sorted(t_stack stack)
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

t_stacklist	*ft_stacknew(int content)
{
	t_stacklist	*ret;

	ret = (t_stacklist *)malloc(sizeof(t_stacklist));
	if (!(ret))
		return (NULL);
	ret->value = content;
	ret->next = NULL;
	return (ret);
}
