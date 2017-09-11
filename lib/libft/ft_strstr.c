/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:24:59 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/12 18:11:33 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int c;
	int i;
	int little_len;

	c = 0;
	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (big[c])
	{
		i = 0;
		while (little[i] == big[i + c])
		{
			if (i == little_len - 1)
				return ((char *)(big + c));
			i++;
		}
		c++;
	}
	return (0);
}
