/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:04:51 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/15 13:36:41 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cursor;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	cursor = *lst;
	while (cursor)
	{
		next = cursor->next;
		ft_lstdelone(cursor, del);
		cursor = next;
	}
	*lst = NULL;
}
