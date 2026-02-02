/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:05:48 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/14 14:02:37 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cursor;

	cursor = lst;
	while (cursor != NULL)
	{
		if (cursor->next == NULL)
			return (cursor);
		cursor = cursor->next;
	}
	return (cursor);
}

// int main()
// {
// 	t_list *n1 = malloc(sizeof(t_list));
// 	t_list *n2 = malloc(sizeof(t_list));
// 	t_list *n3 = malloc(sizeof(t_list));

// 	n1->content = (void *)314;
// 	n2->content = (void *)214;
// 	n3->content = (void *)172;
// 	n1->next = n2;
// 	n2->next = n3;
// 	n3->next = NULL;

// 	printf("%d", (int *)ft_lstlast(n1)->content);
// }

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;
