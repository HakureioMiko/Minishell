/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:05:38 by mickzhan          #+#    #+#             */
/*   Updated: 2026/02/11 11:50:38 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_token	*lstlast(t_token *lst)
// {
// 	t_token	*cursor;

// 	cursor = lst;
// 	while (cursor != NULL)
// 	{
// 		if (cursor->next == NULL)
// 			return (cursor);
// 		cursor = cursor->next;
// 	}
// 	return (cursor);
// }

int	liste_compteur(t_token *token)
{
	int	i;

	i = 0;
	while (token->next != NULL)
	{
		i++;
		token = token->next;
	}
	if (token)
		i++;
	return (i);
}

void	rendu_args(t_token *token, char **cmd)
{
	int	i;

	i = 0;
	while (token->next != NULL)
	{
		cmd[i] = token->sub_token->var;
		i++;
		token = token->next;
	}
}

// Si "$var" geten -> "token"
// Si $var -> cree une fonction qui prend chaque separer d'un espace
// Si '$var' juste afficher $var

bool	lst_last_token(t_token *token)
{
	while (token->next != NULL)
		token = token->next;
	if (token->type != 0)
		return (true);
	return (false);
}

bool	last_next_token(t_token *token)
{
	int	i;

	i = 0;
	while (token->next != NULL)
	{
		if (token->type != 0 && token->next->type != 0)
			return (true);
		token = token->next;
	}
	return (false);
}

bool	check_token(t_token *token)
{
	if (token->type != 0 || lst_last_token(token) == 1
		|| last_next_token(token) == 1)
		return (true);
	return (false);
}

int	parser(t_token *token)
{
	if (check_token(token) == 1)
	{
		ft_printf(2, "PRINTF TESTER : syntax error near unexpected token\n");
		return (ERROR_SYNTAX_STATUS);
	}
	return (0);
}