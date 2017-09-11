/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:34:42 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/15 15:33:53 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		len;

	len = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[i + len] = s2[i];
		i++;
	}
	s1[len + i] = 0;
	return (s1);
}
