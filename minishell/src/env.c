/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:19:17 by mickzhan          #+#    #+#             */
/*   Updated: 2026/02/02 19:34:08 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*lstfirst_env(t_env *lst)
{
	t_env	*cursor;

	cursor = lst;
	while (cursor != NULL)
	{
		if (cursor->previous == NULL)
			return (cursor);
		cursor = cursor->previous;
	}
	return (cursor);
}

t_env	*lstadd_back_env(t_env *lst, char **line)
{
	t_env	*last;
	t_env	*curseur;
	char	*line0;
	char	*line1;

	last = malloc(sizeof(t_env));
	line0 = ft_strdup(line[0]);
	line1 = ft_strdup(line[1]);
	if (!last)
		return (NULL);
	last->key = line0;
	last->content = line1;
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

t_env	*env_content(t_env *env, char **envp)
{
	char	**table;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		j = 0;
		table = ft_split(envp[i], '=');
		env = lstadd_back_env(env, table);
		while (table[j])
		{
			free(table[j]);
			j++;
		}
		free(table);
		i++;
	}
	env = lstfirst_env(env);
	return (env);
}
