/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:08:31 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/04 19:14:21 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *str, int chr)
{
	int	i;

	i = ft_strlen(str);
	if (str[i] == (char) chr)
		return ((char *)str + i);
	i -= 1;
	if (!str)
		return (NULL);
	while (str[i] && i >= 0)
	{
		if (str[i] == (char) chr)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}

// int main()
// {
//     char *str = "bonjour";

//     printf("%s", ft_strrchr(str, 'b'));
// }
