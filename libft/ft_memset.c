/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:27:06 by iharchi           #+#    #+#             */
/*   Updated: 2019/10/11 16:08:03 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned	int		i;
	unsigned	char	*temp;
	unsigned	char	p;

	i = 0;
	temp = (unsigned char *)b;
	p = (unsigned char)c;
	while (i < len)
		temp[i++] = p;
	return (b);
}
