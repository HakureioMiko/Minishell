/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:08:03 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/06 11:48:24 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size && dest[i])
		i++;
	while (src[j])
		j++;
	if (i == size)
		return (size + j);
	while (src[k] && i + k + 1 < size)
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (i + j);
}

// int main()
// {
//     char *src = "HELLO, WORLD";
//     char dest[] = "There is";
//     int total = ft_strlcat(dest, src, 20);

//     printf("%s : < message | len > : %d\n", dest, total);
//     printf("%s", dest);
// }
