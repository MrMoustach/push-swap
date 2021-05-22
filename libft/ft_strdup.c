/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:09:27 by iharchi           #+#    #+#             */
/*   Updated: 2021/05/22 18:34:26 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*p;

if (!(p = (char *)malloc(ft_strlen(str) + 1)))
		return (NULL);
	ft_strlcpy(p, str, ft_strlen(str) + 1);
	return (p);
}
