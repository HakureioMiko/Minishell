/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:07:52 by mickzhan          #+#    #+#             */
/*   Updated: 2025/11/12 10:08:09 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char const *s1, char const *s2, int size)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*string;

	len = ft_strlen(s1) + ft_strlen(s2);
	string = ft_strcat(s1, s2, len);
	return (string);
}

// int main()
// {
//     char s1[] = "";
//     char s2[] = " Nobody was there";

//     printf("%s", ft_strjoin(s1, s2));
// }
