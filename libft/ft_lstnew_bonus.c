/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:36:59 by iharchi           #+#    #+#             */
/*   Updated: 2019/10/16 12:45:18 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
