/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:06:47 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/12 11:38:55 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	string_reverse(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len - 1)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*str;

	i = 0;
	nb = n;
	str = malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	while (i < ft_intlen(n))
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
	{
		i--;
		str[i] = '-';
		i++;
	}
	return (str[i] = '\0', string_reverse(str), str);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_itoa(13121);
// 	printf("%s", str);
// }
