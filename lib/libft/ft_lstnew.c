/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:44:36 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/19 15:13:19 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*copy;

	copy = NULL;
	if (content)
	{
		if (!(copy = malloc(content_size)))
			return (NULL);
		ft_memcpy(copy, content, content_size);
	}
	new = (t_list *)malloc(sizeof(t_list));
	new->content = copy;
	new->next = NULL;
	new->content_size = (content ? content_size : 0);
	return (new);
}
