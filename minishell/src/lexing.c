/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:09:27 by ibrouin-          #+#    #+#             */
/*   Updated: 2026/02/02 16:24:01 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	*lstfirst(t_mini *lst)
{
	t_mini	*cursor;

	cursor = lst;
	while (cursor != NULL)
	{
		if (cursor->previous == NULL)
			return (cursor);
		cursor = cursor->previous;
	}
	return (cursor);
}

t_mini	*lstadd_back(t_mini *lst, char *line)
{
	t_mini	*last;
	t_mini	*curseur;

	last = malloc(sizeof(t_mini));
	if (!last)
		return (NULL);
	last->var = line;
	last->next = NULL;
	if (lst == NULL)
	{
		last->previous = NULL;
		return (last);
	}
	curseur = lst;
	while (curseur->next != NULL)
		curseur = curseur->next;
	curseur->next = last;
	last->previous = curseur;
	return (last);
}

void	printmini(t_mini *mini)
{
	mini = lstfirst(mini);
	if (!mini)
	{
		printf("error\n");
		return ;
	}
	while (mini->next != NULL)
	{
		printf("value string : [%s]\n", mini->var);
		mini = mini->next;
	}
	printf("valeur de fin : debut [%s]\n", mini->var);
	// ta = ta->previous;
	// while (ta->previous != NULL)
	// {
	// 	printf("rvalue ta : [%d]\n", ta->content);
	// 	printf("rank : [%d]\n", ta->rank);
	// 	ta = ta->previous;
	// }
	// printf("rvalue ta : [%d]\n", ta->content);
	// printf("rank : [%d]\n", ta->rank);
}

void	lexing(t_mini *mini_vars, char *line)
{
	char	**table;
	int		i;

	i = 0;
	table = ft_split(line, ' ');
	if (!table)
		return ;
	while (table[i])
	{
		mini_vars = lstadd_back(mini_vars, table[i]);
		i++;
	}
	mini_vars = lstfirst(mini_vars);
	printmini(mini_vars);
}
