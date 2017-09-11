/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:56:13 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/12 19:41:29 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_memset_char(unsigned char *b, unsigned char c, size_t p)
{
	b[p] = c;
}

void			*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	while (i < len)
		ft_memset_char((unsigned char *)b, ch, i++);
	return (b);
}
