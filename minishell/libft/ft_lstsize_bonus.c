/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:06:02 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/13 14:15:12 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// t_list *ft_lstnew(void *content)
// {
//     t_list *node;

//     node = malloc(sizeof(t_list));
//     if (!node)
//         return (NULL);
//     node->content = content;
//     node->next = NULL;
//     return (node);
// }

// int main()
// {
//     t_list *node1;
//     int value = 42;
//     node1 = ft_lstnew(&value);

//     t_list *node2;
//     int value2 = 241;
//     node2 = ft_lstnew(&value2);
//     node1->next = node2;

//     t_list *node3;
//     char str[] = "Hello, Test";
//     node3 = ft_lstnew(&str);
//     node2->next = node3;

//     t_list *node4;
//     char str2[] = "We rolling";
//     node4 = ft_lstnew(&str2);
//     node3->next = node4;

//     printf("%d", ft_lstsize(node1));
// }