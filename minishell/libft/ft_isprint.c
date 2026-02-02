/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:06:32 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/05 09:56:53 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int character)
{
	if (!(character >= 32 && character <= 126))
		return (0);
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_isprintable());
}*/
