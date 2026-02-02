/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:06:09 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/05 14:22:27 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if (!(character >= 'a' && character <= 'z') && !(character >= 'A'
			&& character <= 'Z'))
		return (0);
	return (1);
}

/*int main()
{
	printf("%d", ft_isalpha());
}*/