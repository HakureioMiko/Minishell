/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:49:53 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/14 19:03:08 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct s_list
// {
// 	char			*content;
// 	struct s_list	*next;
// }					t_list;

// void	print_lst(t_list *l)
// {
// 	t_list	*tmp;

// 	tmp = l;
// 	while (tmp)
// 	{
// 		printf("%s\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// }

// void	add_lst(char **tab)
// {
// 	t_list	*head = NULL;
// 	t_list	*cur = NULL;
// 	int		i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		t_list *node = malloc(sizeof(*node));
// 		if (!node)
// 		{
// 			/* In a real program free allocated nodes here */
// 			return ;
// 		}
// 		node->content = tab[i];
// 		node->next = NULL;
// 		if (!head)
// 			head = node;
// 		else
// 			cur->next = node;
// 		cur = node;
// 		i++;
// 	}
// 	print_lst(head);
// 	/* free list (optional for this small test) */
// 	while (head)
// 	{
// 		t_list *tmp = head->next;
// 		free(head);
// 		head = tmp;
// 	}
// }

// int	main(void)
// {
// 	char *tab[] = {"abas", "bbae", "cwfa", "dfaf", NULL};
// 	add_lst(tab);
// }
