/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:14:26 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/15 15:10:23 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node_new;
	t_list	*node_start;

	if (!lst || !f || !del)
		return (NULL);
	node_new = NULL;
	while (lst)
	{
		node_start = ft_lstnew(f(lst->content));
		if (!node_start)
		{
			ft_lstclear(&node_new, del);
			return (NULL);
		}
		ft_lstadd_back(&node_new, node_start);
		lst = lst->next;
	}
	return (node_new);
}
// faire un schema pour bien comprendre
// push et comprendre