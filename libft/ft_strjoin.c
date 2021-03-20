/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:19:37 by iharchi           #+#    #+#             */
/*   Updated: 2019/10/20 15:15:48 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*ret;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(size + 1);
	if (ret == NULL)
		return (ret);
	ft_strlcpy(ret, s1, size + 1);
	ft_strlcpy(ret + ft_strlen(s1), s2, size + 1);
	return (ret);
}
