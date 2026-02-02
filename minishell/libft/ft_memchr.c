/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:06:54 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/05 18:23:05 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)memoryBlock;
	while (i < size)
	{
		if (str[i] == ((unsigned char) searchedChar))
			return (&str[i]);
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char *str = "Hello, World";
//     int array[6] = {8, 4, 6, 1, 7};
//     int number = 'o';
//     int size = 13;

//     printf("%s\n", (char *)ft_memchr(str, number + 258, size));
//     printf("%s\n", (char *)memchr(str, number + 258, size));

//     number = 1;

//     printf("%s\n", (char *)ft_memchr(array, number, size));
//     printf("%s\n", (char *)memchr(array, number, size));
// }
