/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:07:02 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/04 19:32:53 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t	i;
	char	*mem_dest;
	char	*mem_src;

	if (destination == NULL && source == NULL)
		return (NULL);
	i = 0;
	mem_dest = (char *)destination;
	mem_src = (char *)source;
	while (i < size)
	{
		mem_dest[i] = mem_src[i];
		i++;
	}
	return (destination);
}

// int main()
// {
//     char src[] = "BONJOUR, VOUS ALLEZ BIEN?";
//     char dest[50] = "";
//     char dest1[50] = "";

//     memcpy(dest1, src, 15);
//     ft_memcpy(dest, src, 15);
//     printf("%s\n", dest1);
//     printf("%s\n", dest);
// }
