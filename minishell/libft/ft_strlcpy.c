/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:07:59 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/04 20:26:30 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	taille;

	i = 0;
	taille = ft_strlen(src);
	if (size == 0)
		return (taille);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (taille);
}

// int main()
// {
//     char str[] = "Hello, World";
//     char dest[] = "";

//     printf("%d\n", ft_strlcpy(dest, str, 6));
//     printf("%s\n", dest);
// }
