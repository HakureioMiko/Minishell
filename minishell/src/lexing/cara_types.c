/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cara_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrouin- <ibrouin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:11:16 by ibrouin-          #+#    #+#             */
/*   Updated: 2026/02/12 22:23:30 by ibrouin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	angles_brackets_2(char **buffer, char cara, t_token **mini_vars, t_state *state)
{
	if (cara == '<')
	{
		lstadd_back(addnode(HEREDOC), mini_vars, state);
		lstadd_sub_back(add_subnode("<<", NONE), mini_vars, state);
	}
	if (cara == '>')
	{
		lstadd_back(addnode(APPEND), mini_vars, state);
		lstadd_sub_back(add_subnode(">>", NONE), mini_vars, state);
	}
	free(*buffer);
	*buffer = NULL;
}

void	angles_brackets(char **buffer, char cara, t_token **mini_vars, t_state *state)
{
	if (*buffer && (*buffer[0] != '<' && *buffer[0] != '>'))
	{
		if (!(*mini_vars))
			lstadd_back(addnode(WORD), mini_vars, state);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini_vars, state);
		free(*buffer);
		*buffer = NULL;
		*buffer = add_char(*buffer, cara);
	}
	else if (*buffer && *buffer[0] == cara)
		angles_brackets_2(buffer, cara, mini_vars, state);
	else if (*buffer && (*buffer[0] == '>' || *buffer[0] == '<'))
	{
		if (*buffer[0] == '<')
			lstadd_back(addnode(INFILE), mini_vars, state);
		if (*buffer[0] == '>')
			lstadd_back(addnode(OUTFILE), mini_vars, state);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini_vars, state);
		free(*buffer);
		*buffer = NULL;
		*buffer = add_char(*buffer, cara);
	}
	else
		*buffer = add_char(*buffer, cara);
	close_token(mini_vars);
}

void	quotes(char **buffer, char cara, t_token **mini_vars, t_state *state)
{
	if (cara == 39)
	{
		buffer_full(mini_vars, buffer, state);
		*state = IN_S_QUOTE;
	}
	else if (cara == '"')
	{
		buffer_full(mini_vars, buffer, state);
		*state = IN_D_QUOTE;
	}
}

void	brackets(char **buffer, char cara, t_token **mini_vars, t_state *state)
{
	buffer_full(mini_vars, buffer, state);
	if (cara == '(' || cara == ')')
	{
		if (cara == '(')
		{
			lstadd_back(addnode(L_PAR), mini_vars, state);
			lstadd_sub_back(add_subnode("(", NONE), mini_vars, state);
		}
		if (cara == ')')
		{
			lstadd_back(addnode(R_PAR), mini_vars, state);
			lstadd_sub_back(add_subnode(")", NONE), mini_vars, state);
		}
	}
	close_token(mini_vars);
}

void	meta_cara(char **buffer, char cara, t_token **mini_vars, t_state *state)
{
	if (*buffer && (*buffer[0] != '|' && *buffer[0] != '&'))
	{
		if (!(*mini_vars))
			lstadd_back(addnode(WORD), mini_vars, state);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini_vars, state);
		free(*buffer);
		*buffer = NULL;
		*buffer = add_char(*buffer, cara);
	}
	else if (*buffer && *buffer[0] == cara)
	{
		if (cara == '|')
		{
			lstadd_back(addnode(OR), mini_vars, state);
			lstadd_sub_back(add_subnode("||", NONE), mini_vars, state);
		}
		if (cara == '&')
		{
			lstadd_back(addnode(AND), mini_vars, state);
			lstadd_sub_back(add_subnode("&&", NONE), mini_vars, state);
		}
		free(*buffer);
		*buffer = NULL;
	}
	else
		*buffer = add_char(*buffer, cara);
	close_token(mini_vars);
}

void	other_cara(char **buffer, char cara, t_token **mini_vars, t_state *state)
{
	t_token	*current;

	if (*buffer && (*buffer[0] == '>' || *buffer[0] == '<' || *buffer[0] == '|' || *buffer[0] == '&'
		|| *buffer[0] == '(' || *buffer[0] == ')'))
	{
		if (*buffer[0] == '<')
			lstadd_back(addnode(INFILE), mini_vars, state);
		if (*buffer[0] == '>')
			lstadd_back(addnode(OUTFILE), mini_vars, state);
		if (*buffer[0] == '|')
			lstadd_back(addnode(PIPE), mini_vars, state);
		if (*buffer[0] == '&')
			lstadd_back(addnode(WORD), mini_vars, state);
		if (*buffer[0] == '(')
			lstadd_back(addnode(L_PAR), mini_vars, state);
		if (*buffer[0] == ')')
			lstadd_back(addnode(R_PAR), mini_vars, state);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini_vars, state);
		free(*buffer);
		*buffer = NULL;
		close_token(mini_vars);
	}
	if (!*mini_vars)
		lstadd_back(addnode(WORD), mini_vars, state);
	current = find_last(mini_vars);
	if (current->token_state == 0)
		lstadd_back(addnode(WORD), mini_vars, state);
	*buffer = add_char(*buffer, cara);
}
