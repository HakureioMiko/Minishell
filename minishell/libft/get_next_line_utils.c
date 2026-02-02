/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:16:59 by mickzhan          #+#    #+#             */
/*   Updated: 2025/12/04 13:56:22 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_line(size_t nitems, size_t size)
{
	size_t	i;
	char	*allocation;

	i = 0;
	allocation = malloc(nitems * size);
	if (!allocation)
		return (NULL);
	while (i < (nitems * size))
	{
		allocation[i] = 0;
		i++;
	}
	return ((void *)allocation);
}

char	*ft_strcat_line(char *s1, char *s2, int size)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc_line(sizeof(char), size + 1);
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

char	*ft_strjoin_line(char *s1, char *s2)
{
	int		len;
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	string = ft_strcat_line(s1, s2, len);
	free(s1);
	return (string);
}
