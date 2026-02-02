/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:00:43 by mickzhan          #+#    #+#             */
/*   Updated: 2026/01/13 12:32:46 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_word(char c, char word)
{
	if (c == word)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (is_word(s[i], c) == 0 && is_word(s[i + 1], c) == 1)
			count++;
		i++;
	}
	return (count);
}

char	*strdup_sep(const char *str, int len)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	count_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && is_word(s[i], c) == 0)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i])
	{
		while (s[i] && is_word(s[i], c) == 1)
			i++;
		if (s[i])
		{
			len = count_len(s + i, c);
			split[j++] = strdup_sep(s + i, len);
			i += len;
		}
	}
	split[count_word(s, c)] = NULL;
	return (split);
}

// int	main(void)
// {
// 	char **tabstr;
// 	tabstr = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// 	int i = 0;
// 	int o = 4;
// 	printf("resultat de count word : %d\n", count_word("", ' '));

// 	while(i < o)
// 	{
// 		printf("%s\n", tabstr[i]);
// 		i++;
// 	}
// }