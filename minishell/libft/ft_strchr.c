/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:07:37 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/12 17:49:47 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) ch)
			return ((char *) str + i);
		i++;
	}
	if (str[i] == (char) ch)
		return ((char *) str + i);
	return (NULL);
}

// int main()
// {
//     char *str = "Hello, A World";
//     int number = 'l';

//     printf("%s", ft_strchr(str, number));
// }
