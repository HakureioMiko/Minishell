/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:08:26 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/05 16:04:30 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*find == '\0')
		return ((char *) str);
	while (str[i] && i < size)
	{
		while (str[i + j] == find[j] && i + j < size)
		{
			j++;
			if (find[j] == 0)
				return ((char *) str + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

// int main()
// {
//     char str[13] = "Hello, World";
//     char str2[] = "rl";
//     int size = 11;

//     printf("%s\n", strstr(str, str2));
//     printf("%s\n", ft_strnstr(str, str2, size));
// }
