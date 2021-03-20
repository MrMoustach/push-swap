/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:52:52 by iharchi           #+#    #+#             */
/*   Updated: 2019/10/11 15:36:41 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			tmp = (char *)s;
		s++;
	}
	if (c == '\0')
		return (char *)s;
	return (tmp);
}
