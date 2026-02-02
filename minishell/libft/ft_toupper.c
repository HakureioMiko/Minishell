/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:09:20 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/05 09:57:54 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	return (ch);
}

/*int main()
{
	int i = 0;
	char *str = "Hello, World";
	char ch;

	while (str[i])
	{
		ch = str[i];
		printf("%c", ft_toupper(ch));
		i++;
	}
}*/
