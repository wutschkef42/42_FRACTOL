/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 21:24:45 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/17 14:02:47 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*str;

	if (!(str = ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(str, (size + 1));
	return ((char *)str);
}
