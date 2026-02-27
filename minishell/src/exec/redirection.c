/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrouin- <ibrouin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:01:11 by ibrouin-          #+#    #+#             */
/*   Updated: 2026/02/26 20:09:34 by ibrouin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void    redirection(t_ast *node)
{
	int	fd;

	if (!node->redirs)
		return;
	while (node->redirs)
	{
		if (node->redirs->type == 1)
		{
			fd = open(node->redirs->target->sub_token->var, O_RDONLY);
			if (fd < 0)
			{
				perror("minishell");
				exit (127);
			}
			dup2(fd, 0);
			close(fd);
		}
		if (node->redirs->type == 2)
		{
			fd = open(node->redirs->target->sub_token->var, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd < 0)
			{
				perror("minishell");
				exit (127);
			}
			dup2(fd, 1);
			close(fd);
		}
		if (node->redirs->type == 3)
			printf("here_doc");
		if (node->redirs->type == 4)
			printf("append");
		node->redirs = node->redirs->next;
	}
}
