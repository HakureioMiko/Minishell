/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:16:59 by mickzhan          #+#    #+#             */
/*   Updated: 2025/12/10 16:21:35 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	i;
	void	*allocation;
	char	*space;

	i = 0;
	allocation = malloc(nitems * size);
	if (!allocation)
		return (NULL);
	space = (char *)allocation;
	while (space[i])
	{
		space[i] = 0;
		i++;
	}
	return ((void *)allocation);
}
// int main()
// {
// 	int nitems = 16;
// 	int size = 1;
// 	int i = 0;
// 	char hello[] = "Hello, World i am good";
// 	char boite;
// 	char *str;

// 	str = ft_calloc(nitems, size);

// 	while (i < nitems)
// 	{
// 		printf("%d", str[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	i = 0;
// 	while (i < nitems)
// 	{
// 		str[i] = hello[i];
// 		i++;
// 	}
// 	printf("%s", str);
// 	return (0);
// }