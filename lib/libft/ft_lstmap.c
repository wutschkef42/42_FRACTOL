/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:13:30 by erucquoy          #+#    #+#             */
/*   Updated: 2017/04/24 16:22:22 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*lst_map;
	t_list	*lst_tmp;

	if (!lst || !(lst_map = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	lst_map = f(lst);
	lst_tmp = lst_map;
	while (lst->next)
	{
		lst_tmp->next = f(lst->next);
		lst_tmp = lst_tmp->next;
		lst = lst->next;
	}
	return (lst_map);
}
