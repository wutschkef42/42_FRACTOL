/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:43:41 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/12 16:37:06 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int i;
	int len;

	len = ft_strlen(s1);
	i = 0;
	while (s2[i] != 0)
	{
		s1[i + len] = s2[i];
		i++;
	}
	s1[len + i] = 0;
	return (s1);
}
