/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:55:13 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/17 14:09:14 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_memcpy_ch(char *dst, const char *src, char c, size_t pos)
{
	dst[pos] = src[pos];
	if (src[pos] == c)
	{
		return (1);
	}
	return (0);
}

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (ft_memcpy_ch((char *)dst, (char *)src, (char)c, i))
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
