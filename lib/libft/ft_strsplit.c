/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 15:39:49 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/25 13:32:09 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_create_tab(char const *s, char c)
{
	int		i;
	int		ok;
	int		count;
	char	**tab;

	i = 0;
	count = 0;
	while (s[i])
	{
		ok = 0;
		while (s[i] && (s[i] == c))
			i++;
		while (s[i] && !(s[i] == c))
		{
			ok++;
			i++;
		}
		if (ok > 0)
			count += ok;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	return (tab);
}

static char	**ft_malloc_tab(char const *s, char c)
{
	char	**tab;
	int		i;
	int		letters;
	int		count;

	if (!(tab = ft_create_tab(s, c)))
		return (NULL);
	i = 0;
	count = 0;
	while (s[i])
	{
		letters = 0;
		while (s[i] && (s[i] == c))
			i++;
		while (s[i] && !(s[i] == c))
		{
			letters++;
			i++;
		}
		if (letters > 0)
			if (!(tab[count++] = ft_strnew((size_t)letters)))
				return (NULL);
	}
	return (tab);
}

static char	**ft_fill_tab(char const *s, char c)
{
	char	**tab;
	int		i;
	int		count;
	int		letters;

	i = 0;
	count = 0;
	if (!(tab = ft_malloc_tab(s, c)))
		return (NULL);
	while (s[i])
	{
		letters = 0;
		while (s[i] && (s[i] == c))
			i++;
		while (s[i] && !(s[i] == c))
			tab[count][letters++] = s[i++];
		if (letters > 0)
		{
			tab[count][letters] = '\0';
			count++;
		}
	}
	tab[count] = (char *)malloc(2);
	tab[count] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char **tab;

	if (!s || !c)
		return (NULL);
	if (!(tab = ft_fill_tab(s, c)))
		return (NULL);
	return (tab);
}
