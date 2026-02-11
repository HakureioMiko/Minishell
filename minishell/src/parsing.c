/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:05:38 by mickzhan          #+#    #+#             */
/*   Updated: 2026/02/11 17:25:29 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*lstfirst_token(t_token *lst)
{
	t_token	*cursor;

	cursor = lst;
	while (cursor != NULL)
	{
		if (cursor->sub_token->prev == NULL)
			return (cursor);
		cursor->sub_token = cursor->sub_token->prev;
	}
	return (cursor);
}

int	cmd_compteur(t_token *token)
{
	int		i;
	t_token	*tmp;

	i = 1;
	tmp = token;
	if (!tmp)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->type != 0)
			i++;
		tmp = tmp->next;
	}
	if (tmp->type != 0)
		i++;
	return (i);
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

int	len_cmd_sub(t_token *token)
{
	int		i;
	t_token	*tmp;

	i = 1;
	tmp = token;
	if (!tmp)
		return (0);
	while (tmp->sub_token->next != NULL)
	{
		i++;
		tmp->sub_token = tmp->sub_token->next;
	}
    tmp = lstfirst_token(tmp);
	return (i);
}

t_cmd	*lstadd_back_cmd(t_cmd *lst)
{
	t_cmd	*last;
	t_cmd	*curseur;

	last = malloc(sizeof(t_cmd));
	if (!last)
		return (NULL);
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

// t_cmd	*cmd_list(t_cmd *cmd, t_token *token)
// {
// 	int	i;

// 	i = 0;
// 	while (token->next != NULL)
// 	{
// 		cmd = lstadd_back_cmd(cmd);
// 		cmd->argv = malloc(sizeof(char *) * len_cmd_sub(token));
// 		while (token->sub_token->next != NULL)
// 		{
// 			strcpy(cmd->argv[i], token->sub_token->var);
// 			printf("THIS IS CMD ARGV : [%s]\n", cmd->argv[i]);
// 			i++;
// 			token->sub_token = token->sub_token->next;
// 		}
// 		if (token->sub_token->var)
// 		{
// 			strcpy(cmd->argv[i], token->sub_token->var);
// 			printf("THIS IS CMD ARGV : [%s]\n", cmd->argv[i]);
// 		}
// 		token = token->next;
// 	}
// 	return (cmd);
// }

int	parser(t_token *token, t_env *env)
{
	t_cmd	*cmd;
	int		cmd_sub;

	(void)env;
	cmd = NULL;
	cmd_sub = len_cmd_sub(token);
    token = lstfirst_token(token);
	// printf("%s TEST :[%s]\n%s", RED, token->sub_token->var, RESET);
	// printf("%s TEST :[%s]\n%s", RED, token->sub_token->prev->var, RESET);
	if (check_token(token) == 1)
	{
		ft_printf(2, "PRINTF TESTER : syntax error near unexpected token\n");
		return (ERROR_SYNTAX_STATUS);
	}
	// cmd = cmd_list(cmd, token);
	// printf("CMD TABLEAU [%s]\n", cmd->argv[1]);
	return (0);
}
