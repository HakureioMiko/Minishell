/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:07:07 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/07 17:25:34 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destinaton, const void *source, size_t size)
{
	size_t		i;
	const char	*mem_src;
	char		*mem_dest;

	if (destinaton == NULL && source == NULL)
		return (destinaton);
	i = 0;
	mem_dest = (char *)destinaton;
	mem_src = (const char *)source;
	if (source >= destinaton)
		ft_memcpy(destinaton, source, size);
	else
	{
		while (size > i)
		{
			mem_dest[size - 1] = mem_src[size - 1];
			size--;
		}
	}
	return (destinaton);
}

// int main()
// {
//     char src[100] = "Geeksfor";
//     char second[100] = "Geeksfor";

//     memmove(second + 2, src, 6);
//     printf("%s\n", second);

//     ft_memmove(src + 2, src, 6);
//     printf("%s\n", src);
// }
