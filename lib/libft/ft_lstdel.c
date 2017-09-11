/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:42:05 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/24 15:27:32 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*el;

	if (!(alst && del))
		return ;
	el = (*alst);
	while (el)
	{
		del(el->content, el->content_size);
		free(el);
		el = el->next;
	}
	*alst = NULL;
}
