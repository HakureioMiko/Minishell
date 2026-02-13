/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrouin- <ibrouin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:30:32 by ibrouin-          #+#    #+#             */
/*   Updated: 2026/02/12 22:27:01 by ibrouin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*add_char(char *buffer, char new)
{
	char	*temp;
	int		len;
	int		i;

	if (!buffer)
		len = 0;
	else
		len = ft_strlen(buffer);
	i = 0;
	temp = malloc(sizeof(char) * len + 2);
	if (!temp)
		return (NULL);
	if (buffer)
	{
		while (buffer[i] != '\0')
		{
			temp[i] = buffer[i];
			i++;
		}
	}
	temp[i] = new;
	i++;
	temp[i] = '\0';
	free(buffer);
	return (temp);
}

void	close_token(t_token **mini_vars)
{
	t_token	*current;

	if (*mini_vars)
	{
		current = find_last(mini_vars);
		current->token_state = 0;
	}
}

void	buffer_full(t_token **mini_vars, char **buffer, t_state *state)
{
	if (!*buffer)
		return ;
	if (*buffer && (*buffer[0] != '<' && *buffer[0] != '>' && *buffer[0] != '|' && *buffer[0] != '&'))
	{
		if (!(*mini_vars))
			lstadd_back(addnode(WORD), mini_vars, state);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini_vars, state);
		free(*buffer);
		*buffer = NULL;
	}
	else if (*buffer && (*buffer[0] == '<' || *buffer[0] == '>' || *buffer[0] == '|'
		|| *buffer[0] == '&'))
	{
		if (*buffer[0] == '<')
			lstadd_back(addnode(INFILE), mini_vars, state);
		if (*buffer[0] == '>')
			lstadd_back(addnode(OUTFILE), mini_vars, state);
		if (*buffer[0] == '|')
			lstadd_back(addnode(PIPE), mini_vars, state);
		if (*buffer[0] == '&')
			lstadd_back(addnode(WORD), mini_vars, state);
		lstadd_sub_back(add_subnode(*buffer, NONE), mini_vars, state);
		free(*buffer);
		*buffer = NULL;
		close_token(mini_vars);
	}
}

void	in_d_quote_state(char **buf, char c, t_state *st, t_token **mini)
{
	if (*mini)
	{
		if (find_last(mini)->token_state == 0)
			lstadd_back(addnode(WORD), mini, st);
	}
	if (c == '"')
	{
		if (!(*mini))
			lstadd_back(addnode(WORD), mini, st);
		if (!*buf)
			lstadd_sub_back(add_subnode("", DOUBLE), mini, st);
		if (*buf)
		{
			lstadd_sub_back(add_subnode(*buf, DOUBLE), mini, st);
			free(*buf);
			*buf = NULL;
		}
		*st = NORMAL;
	}
	else if (c >= ' ' && c <= '~')
		*buf = add_char(*buf, c);
}

void	in_s_quote_state(char **buf, char c, t_state *st, t_token **mini)
{
	if (*mini)
	{
		if (find_last(mini)->token_state == 0)
			lstadd_back(addnode(WORD), mini, st);
	}
	if (c == 39)
	{
		if (!(*mini))
			lstadd_back(addnode(WORD), mini, st);
		if (!*buf)
			lstadd_sub_back(add_subnode("", SINGLE), mini, st);
		if (*buf)
		{
			lstadd_sub_back(add_subnode(*buf, SINGLE), mini, st);
			free(*buf);
			*buf = NULL;
		}
		*st = NORMAL;
	}
	else if (c >= ' ' && c <= '~')
		*buf = add_char(*buf, c);
}
