/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrouin- <ibrouin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:35:43 by ibrouin-          #+#    #+#             */
/*   Updated: 2026/02/27 15:36:33 by ibrouin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	*ft_malloc(size_t size)
{
	static int	count = 0;

	count++;
	if (count == 5) // fait échouer le 5e malloc
	{
		return (NULL);
	}
	return (malloc(size));
}