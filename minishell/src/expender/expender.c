/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:29:35 by mickzhan          #+#    #+#             */
/*   Updated: 2026/02/17 11:47:48 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


// copy permet de copie la valeur de $
// paste permet de la mettre en leurs valeur et le renvoye 

typedef struct s_exp
{
	int				last_command;

	char			*copy;
	char			*paste;
	t_state			state;
	t_env			*env;
	bool			in_doc;
	struct s_exp	*next;
}					t_exp;

bool	check_left_exp(t_ast *ast)
{
	if (ast->type == AST_WORD)
		return (true);
	return (false);
}

bool	check_right_exp(t_ast *ast)
{
	if (ast->type == AST_WORD)
		return (true);
	return (false);
}

t_ast	*expand_function(t_ast *ast, t_env *env)
{
	t_ast	*curseur;
	t_exp	*exp;

	exp = malloc(sizeof(t_exp));
	curseur = ast;
	if (curseur->type != AST_WORD)
	{
		if (curseur->left)
			check_left_exp(ast);
		if (curseur->right)
			check_right_exp(ast);
	}
	return (ast);
}
