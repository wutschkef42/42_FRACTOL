/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:39:45 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/12 19:54:30 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memcpy_ch(char *dst, const char *src, size_t pos)
{
	dst[pos] = src[pos];
}

void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		ft_memcpy_ch((char *)dst, (char *)src, i++);
	return (dst);
}
