/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:07:21 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/07 10:55:00 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	char	*char_memset;
	size_t	i;

	if (count == 0)
		return (pointer);
	char_memset = (char *)pointer;
	i = 0;
	while (i < count)
	{
		char_memset[i] = value;
		i++;
	}
	return (pointer);
}

// int main()
// {
//     char src[] = "Hello, Salut ca va?";
//     char src1[] = "Hello, Salut ca va?";

//     int int_value[] = {-10, 5, 7, 12, 3};
//     int int_value2[] = {10, 5, -7, 12, 3};

//     int value = 65;
//     int size = 3;
//     int i = 0;

//     memset(src, value, size);
//     ft_memset(src1, value, size);

// 	while (i < 5)
//     {
//         printf("%d ", int_value[i]);
//         i++;
//     }
// 	printf("\n");
// 	i = 0;
// 	while (i < 5)
//     {
//         printf("%d ", int_value2[i]);
//         i++;
//     }
// 	i = 0;
// 	printf("\n");
//     memset(int_value2, value, sizeof(int) * size);
//     ft_memset(int_value, value, sizeof(int) * size);

//     printf("%s\n", src);
//     printf("%s\n", src + 7);
//     printf("%s\n", src1);
//     printf("%s\n", src1 + 7);
//     while (i < 5)
//     {
//         printf("%d ", int_value[i]);
//         i++;
//     }
//     i = 0;
//     printf("\n");
//     while (i < 5)
//     {
//         printf("%d ", int_value2[i]);
//         i++;
//     }
// }
