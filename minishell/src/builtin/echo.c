/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:26:08 by mickzhan          #+#    #+#             */
/*   Updated: 2026/02/10 11:24:08 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	function_echo(char *parse, bool option)
{
	if (parse && option)
	{
		ft_printf(1, "%s", parse);
		return (false);
	}
	else if (parse)
	{
		ft_printf(1, "%s\n", parse);
		return (false);
	}
	else
		return (true);
}
