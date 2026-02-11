/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:13:10 by mickzhan          #+#    #+#             */
/*   Updated: 2026/02/11 17:26:37 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signum)
{
	(void)signum;
	printf("\n%sMinishell >%s", RED, RESET);
}

// SIGQUIT = CTRL + '\'
// SIGINT = CTRL + C
// SIGTSTP = CTRL + Z
// signal(SIGQUIT, SIG_IGN);
// signal(SIGINT, handler);


int	main(int ac, char **av, char **envp)
{
	char		*line;
	t_token		*mini_vars;
	t_env		*env;

	(void)av;
	(void)ac;
	mini_vars = NULL;
	env = NULL;
	env = env_content(env, envp);
	while (true)
	{
		line = readline("Minishell > ");
		if (line)
		{
			mini_vars = lexing(&mini_vars, line);
			parser(mini_vars, env);
		}
		if (*line)
			add_history(line);
		if (!line)
		{
			free(line);
			if (mini_vars)
				ft_miniclear(&mini_vars);
			return (0);
		}
		if (mini_vars)
		{
			printmini(&mini_vars);
			ft_miniclear(&mini_vars);
		}
		free(line);
	}
}

// Test KILL
// int	main(void)
// {
// 	int pid;

// 	pid = 362178;
// 	kill(pid, SIGQUIT);
// }