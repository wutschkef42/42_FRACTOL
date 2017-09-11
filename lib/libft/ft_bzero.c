/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:37:25 by erucquoy          #+#    #+#             */
/*   Updated: 2017/09/06 17:08:49 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *b, size_t n)
{
	unsigned int	i;
	unsigned char	*s;
	
	i = 0;
	s = (unsigned char *) b;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}
