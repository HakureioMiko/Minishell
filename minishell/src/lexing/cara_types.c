/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cara_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrouin- <ibrouin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:11:16 by ibrouin-          #+#    #+#             */
/*   Updated: 2026/02/27 15:26:43 by ibrouin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	angles_brackets_2(char **buf, char cara, t_token **mini, t_state *state)
{
	if (cara == '<')
	{
		lstadd_back(addnode(HEREDOC), mini, state);
		lstadd_sub_back(add_subnode("<<", NONE), mini, state);
	}
	if (cara == '>')
	{
		lstadd_back(addnode(APPEND), mini, state);
		lstadd_sub_back(add_subnode(">>", NONE), mini, state);
	}
	free(*buf);
	*buf = NULL;
}

void	angle_bracket(char **buffer, char cara, t_token **mini, t_state *state)
{
	if (*buffer && (*buffer[0] != '<' && *buffer[0] != '>'))
	{
		if (!(*mini))
			lstadd_back(addnode(WORD), mini, state);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini, state);
		free(*buffer);
		*buffer = NULL;
		*buffer = add_char(*buffer, cara, state);
	}
	else if (*buffer && *buffer[0] == cara)
		angles_brackets_2(buffer, cara, mini, state);
	else if (*buffer && (*buffer[0] == '>' || *buffer[0] == '<'))
	{
		if (*buffer[0] == '<')
			lstadd_back(addnode(INFILE), mini, state);
		if (*buffer[0] == '>')
			lstadd_back(addnode(OUTFILE), mini, state);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini, state);
		free(*buffer);
		*buffer = NULL;
		*buffer = add_char(*buffer, cara, state);
	}
	else
		*buffer = add_char(*buffer, cara, state);
	close_token(mini);
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

void	meta_cara_3(char **buffer, char cara, t_token **mini, t_state *state)
{
	if (cara == '|')
	{
		lstadd_back(addnode(OR), mini, state);
		lstadd_sub_back(add_subnode("||", NONE), mini, state);
	}
	if (cara == '&')
	{
		lstadd_back(addnode(AND), mini, state);
		lstadd_sub_back(add_subnode("&&", NONE), mini, state);
	}
	free(*buffer);
	*buffer = NULL;
}

void	meta_cara_2(char **buffer, char cara, t_token **mini, t_state *state)
{
	if (!(*mini))
		lstadd_back(addnode(WORD), mini, state);
	lstadd_sub_back(add_subnode(*buffer, NONE), mini, state);
	free(*buffer);
	*buffer = NULL;
	*buffer = add_char(*buffer, cara, state);
}

void	meta_cara(char **buffer, char cara, t_token **mini_vars, t_state *state)
{
	if (*buffer && (*buffer[0] != '|' && *buffer[0] != '&'))
		meta_cara_2(buffer, cara, mini_vars, state);
	else if (*buffer && (*buffer[0] == '&' && cara == '|'))
		meta_cara_2(buffer, cara, mini_vars, state);
	else if (*buffer && (*buffer[0] == '|' && cara == '&'))
	{
		if (!(*mini_vars))
			lstadd_back(addnode(PIPE), mini_vars, state);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini_vars, state);
		free(*buffer);
		*buffer = NULL;
		*buffer = add_char(*buffer, cara, state);
	}
	else if (*buffer && *buffer[0] == cara)
		meta_cara_3(buffer, cara, mini_vars, state);
	else
		*buffer = add_char(*buffer, cara, state);
	close_token(mini_vars);
}

void	other_cara_if(char **buffer, t_token **mini_vars, t_state *state)
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
}

void	other_cara(char **buffer, char cara, t_token **mini, t_state *state)
{
	t_token	*current;

	if (*buffer && (*buffer[0] == '>' || *buffer[0] == '<' || *buffer[0] == '|'
			|| *buffer[0] == '&' || *buffer[0] == '(' || *buffer[0] == ')'))
	{
		other_cara_if(buffer, mini, state);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini, state);
		free(*buffer);
		*buffer = NULL;
		close_token(mini);
	}
	if (!*mini)
		lstadd_back(addnode(WORD), mini, state);
	current = find_last(mini);
	if (current->token_state == 0)
		lstadd_back(addnode(WORD), mini, state);
	*buffer = add_char(*buffer, cara, state);
}
