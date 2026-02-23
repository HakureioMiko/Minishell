/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:29:35 by mickzhan          #+#    #+#             */
/*   Updated: 2026/02/23 15:35:15 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// copy permet de copie la valeur de $
// paste permet de la mettre en leurs valeur et le renvoye

// typedef struct s_exp
// {
// 	int				last_command;

// 	char			*copy;
// 	char			*paste;
// 	t_state			state;
// 	t_env			*env;
// 	bool			in_doc;
// 	struct s_exp	*next;
// }					t_exp;

bool	check_if_word(t_ast *ast)
{
	if (ast->type == AST_CMD)
		return (true);
	return (false);
}

bool	check_if_expendable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (true);
		i++;
	}
	return (false);
}

// int	len_dollars(char *ast)
// {
// 	int	i;

// 	i = 0;
// 	while (ast[i])
// 	{
// 		if (ast[i] == ' ' || ast[i] == '$')
// 			return (i);
// 		i++;
// 	}
// 	return (i);
// }

char	*check_string(char *str, t_env *env)
{
	char	*str_env;

	if (!str)
		return (NULL);
	str_env = NULL;
	while (env != NULL)
	{
		if (ft_strncmp(env->key, str, -1) == 0)
		{
			str_env = ft_strdup(env->content);
			break ;
		}
		env = env->next;
	}
	return (str_env);
}

char	*check_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while ((str[i] != ' ' && str[i]) && (str[i] != '$' && str[i]))
		i++;
	key = malloc(sizeof(char) * (i + 1));
	if (!key)
		return (NULL);
	i = 0;
	while ((str[i] != ' ' && str[i]) && (str[i] != '$' && str[i]))
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*check_new_string(char *str, char *key, char *env)
{
	int		i;
	int		j;
	int		k;
	int		len;
	int		count;
	char	*new_string;

	i = 0;
	k = 0;
	count = 0;
	len = ft_strlen(str) + ft_strlen(env) - ft_strlen(key) - 1;
	new_string = malloc(sizeof(char) * (len + 1));
	if (!new_string)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$' && count == 0 && env != NULL)
		{
			i++;
			j = 0;
			i += ft_strlen(key);
			count++;
			while (env[j])
			{
				new_string[k] = env[j];
				j++;
				k++;
			}
		}
		else if (env == NULL && str[i] == '$' && count == 0)
			i += ft_strlen(key) + 1;
		new_string[k] = str[i];
		i++;
		k++;
	}
	new_string[k] = '\0';
	free(str);
	return (new_string);
}

// char	*new_string(char *str, t_env *env)
// {
// 	int		i;
// 	char	*str_key;
// 	char	*str_env;
// 	char	*new_str;
// 	char	*temp;

// 	i = 0;
// 	if (!str)
// 		return (NULL);
// 	new_str = ft_strdup(str);
// 	if (!new_str)
// 		return (NULL);
// 	while (new_str[i])
// 	{
//         printf("CONTENT CHAR: %c\n", new_str[i]);
// 		if (new_str[i] == '$')
// 		{
// 			i++;
//             printf("NEW_STRING AVANT : %s\n", new_str);
// 			str_key = check_key(new_str + i);
// 			str_env = check_string(str_key, env);
// 			if (str_env)
// 			{
// 				temp = check_new_string(new_str, str_key, str_env);
// 				new_str = temp;
//                 i = 0;
// 			}
// 			else
// 				i += ft_strlen(str_key) + 1;
// 			free(str_key);
// 			free(str_env);
// 		}
// 		else
// 			i++;
// 	}
//     printf("NEW_STRING APRES : %s\n", new_str);
// 	free(str);
// 	return (new_str);
// }

char	*new_string(char *str, t_env *env)
{
	int		i;
	char	*key;
	char	*content;
	char	*new_str;
	char	*tmp;

	i = 0;
	new_str = ft_strdup(str);
	while (new_str[i])
	{
		if (new_str[i] == '$')
		{
			i++;
			key = check_key(new_str + i);
			content = check_string(key, env);
			tmp = check_new_string(new_str, key, content);
			new_str = tmp;
			i = 0;
		}
		i++;
	}
	free(str);
	return (new_str);
}

char	*app_expend(char *ast, t_env *env, bool state)
{
	if (!ast)
		return (NULL);
	if (check_if_expendable(ast) == 0)
		return (ast);
	else
	{
		if (state == true)
			ast = new_string(ast, env);
		else if (state == false)
			ast = new_string(ast, env);
	}
	return (ast);
}

// changer a partir de a ne pas changer var mais mettre dans un tableau

t_ast	*call_expand(t_ast *ast, t_env *env)
{
	t_token		*current_token;
	t_sub_token	*current_sub;
	char		**tmp;
	int			i;
	int			j;

	ast->cmd = malloc(sizeof(char *) * 100);
	i = 0;
	j = 0;
	current_token = ast->cmd_token;
	while (current_token != NULL && current_token->type == WORD)
	{
		current_sub = current_token->sub_token;
		while (current_sub != NULL)
		{
			if (current_sub->quote == DOUBLE)
			{
				current_sub->var = app_expend(current_sub->var, env, true);
				ast->cmd[i] = ft_strdup(current_sub->var);
				i++;
			}
			else if (current_sub->quote == NORMAL)
			{
				current_sub->var = app_expend(current_sub->var, env, false);
				tmp = ft_split(current_sub->var, ' ');
				while (tmp[j])
				{
					ast->cmd[i] = ft_strdup(tmp[j]);
					j++;
					i++;
				}
			}
			j = 0;
			current_sub = current_sub->next;
		}
		current_token = current_token->next;
	}
	ast->cmd[i] = NULL;
	i = 0;
	while (ast->cmd[i])
	{
		printf("%s\n", ast->cmd[i]);
		i++;
	}
	return (ast);
}

// call expend de la version cmd
// t_ast	*call_expand(t_ast *ast, t_env *env)
// {
// 	t_sub_token	*current_sub;

// 	current_sub = ast->cmd_token->sub_token;
// 	if (current_sub->quote == DOUBLE)
// 		current_sub->var = app_expend(current_sub->var, env, true);
// 	else if (current_sub->quote == NORMAL)
// 		current_sub->var = app_expend(current_sub->var, env, false);
// 	return (ast);
// }

t_ast	*expand_ast_checker(t_ast *curseur, t_env *env)
{
	if (!curseur)
		return (NULL);
	if (check_if_word(curseur) == 1)
		call_expand(curseur, env);
	if (curseur->left)
		expand_ast_checker(curseur->left, env);
	if (curseur->right)
		expand_ast_checker(curseur->right, env);
	return (curseur);
}

t_ast	*expand_function(t_ast *ast, t_env *env)
{
	t_ast	*curseur;

	curseur = ast;
	ast = expand_ast_checker(curseur, env);
	return (ast);
}
