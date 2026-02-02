/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:05:50 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/13 10:03:42 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*char_ptr;

	i = 0;
	char_ptr = (char *)ptr;
	while (i < n)
	{
		char_ptr[i] = 0;
		i++;
	}
}

// int main()
// {
// 	char str[] = "No one loved";
// 	int n = 1;

// 	ft_bzero(str, n);
// 	printf("%s\n", str);
// 	printf("%s\n", str + 1);
// 	printf("%s\n", str + 2);
// 	printf("%s\n", str + 3);
// 	printf("%s\n", str + 4);
// 	printf("%s\n", str + 5);
// }
