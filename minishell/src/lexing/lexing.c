/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:09:27 by ibrouin-          #+#    #+#             */
/*																			*/
/*   Updated: 2026/02/03 16:44:07 by ibrouin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	normal_state(char **buffer, char cara, t_state *state, t_token **mini)
{
	if ((cara == ' ') || (cara >= 7 && cara <= 13))
	{
		buffer_full(mini, buffer);
		close_token(mini);
	}
	else if (cara == '|')
		meta_cara(buffer, cara, mini);
	else if (cara == '<' || cara == '>')
		angles_brackets(buffer, cara, mini);
	else if (cara == 39 || cara == '"')
		quotes(buffer, cara, mini, state);
	else if (cara >= '!' && cara <= '~')
		other_cara(buffer, cara, mini);
}

int	cara_iteration(char *line, char **buffer, t_token **mini_vars)
{
	int		i;
	t_state	state;

	i = 0;
	state = NORMAL;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (0);
	while (line[i] != '\0')
	{
		if (state == NORMAL)
			normal_state(buffer, line[i], &state, mini_vars);
		else if (state == IN_D_QUOTE)
			in_d_quote_state(buffer, line[i], &state, mini_vars);
		else if (state == IN_S_QUOTE)
			in_s_quote_state(buffer, line[i], &state, mini_vars);
		i++;
	}
	return (1);
}

void	last_token(char **buffer, t_token **mini_vars)
{
	t_token	*current;

	if (*buffer[0] == '<')
	{
		lstadd_back(addnode(INFILE), mini_vars);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini_vars);
	}
	else if (*buffer[0] == '>')
	{
		lstadd_back(addnode(OUTFILE), mini_vars);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini_vars);
	}
	else if (*buffer[0] != '|')
	{
		if (!(*mini_vars))
			lstadd_back(addnode(WORD), mini_vars);
		current = find_last(mini_vars);
		if (current->token_state == 0)
			lstadd_back(addnode(WORD), mini_vars);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini_vars);
	}
	free(*buffer);
}

t_token	*lexing(t_token **mini_vars, char *line)
{
	char	*buffer;

	buffer = NULL;
	cara_iteration(line, &buffer, mini_vars);
	if (buffer)
		last_token(&buffer, mini_vars);
	if (!(*mini_vars))
		lstadd_back(addnode(WORD), mini_vars);
	return (*mini_vars);
}
