/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:31:27 by mickzhan          #+#    #+#             */
/*   Updated: 2026/02/06 14:53:21 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pwd	*current_directory_path(t_pwd *pwd)
{
	char	cdw[1024];
	int		i;

	i = strlen(getcwd(cdw, sizeof((cdw))));
	if (i == 0)
		perror("getwcd");
	if (pwd->oldpwd && pwd->pwd)
	{
		free(pwd->oldpwd);
		pwd->oldpwd = pwd->pwd;
	}
	else
	{
		pwd->pwd = malloc(sizeof(char) * (i + 1));
		strcpy(pwd->pwd, cdw);
		pwd->oldpwd = pwd->pwd;
	}
	return (pwd);
}
