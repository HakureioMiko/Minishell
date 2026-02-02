/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:08:58 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/04 18:46:57 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	return (ch);
}

// int main()
// {
//     int i = 0;
//     char *str = "hELLO, wORLD";
//     char ch;

//     while (str[i])
//     {
//         ch = str[i];
//         printf("%c", ft_tolower(ch));
//         i++;
//     }
// }
