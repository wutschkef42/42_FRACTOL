/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:48:22 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/25 12:41:36 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	char	t;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	j = len - 1;
	while (i < len / 2)
	{
		t = str[i];
		str[i] = str[j];
		str[j] = t;
		i++;
		j--;
	}
	str[len] = '\0';
	return (str);
}

static int	ft_malloc_len(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n >= 0 && n < 10)
		return (2);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_special(int n, char *s)
{
	int i;

	i = 0;
	if (n == 0)
	{
		s[i] = '0';
		return (s);
	}
	if (n == (-2147483647 - 1))
	{
		s[i] = '8';
		n /= 10;
		n *= -1;
		i++;
		while (n > 0)
		{
			s[i] = "0123456789"[(n % 10)];
			n /= 10;
			i++;
		}
		s[i] = '-';
		return (ft_strrev(s));
	}
	return (NULL);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		neg;

	neg = n < 0 ? 1 : 0;
	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * ft_malloc_len(n) + 1)))
		return (NULL);
	if ((ft_special(n, res)) != NULL)
		return (res);
	if (neg)
		n *= -1;
	while (n > 0)
	{
		res[i] = "0123456789"[(n % 10)];
		i++;
		n /= 10;
	}
	if (neg)
		res[i++] = '-';
	res[i] = 0;
	return (ft_strrev(res));
}
