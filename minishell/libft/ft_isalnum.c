/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:06:03 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/05 09:56:23 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if (!(character >= '0' && character <= '9') && !(character >= 'a'
			&& character <= 'z') && !(character >= 'A' && character <= 'Z'))
		return (0);
	return (1);
}

/*int main()
{
	printf("%d", ft_isalnum('0'));
}*/
