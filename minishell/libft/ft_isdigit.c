/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:06:26 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/14 15:48:14 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int character)
{
	if (!(character >= '0' && character <= '9'))
		return (0);
	return (1);
}

/*int main()
{
	printf("%d", ft_isdigit("728181"));
}*/
