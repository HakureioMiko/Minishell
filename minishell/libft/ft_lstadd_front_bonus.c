/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:06:10 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/14 12:11:08 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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
//     t_list *lst;
//     char str[] = "Hello";
//     lst = ft_lstnew(&str);
//     t_list *new;
//     char str2[] = "Base";
//     new = ft_lstnew(&str2);
// 	t_list *new1;

//     printf("%s\n", (char *)lst->content);
//     printf("%s\n", (char *)new->content);

//     ft_lstadd_front(&lst, new);

//     printf("%s\n", (char *)lst->content);
//     printf("%s\n", (char *)new->next->content);
// }