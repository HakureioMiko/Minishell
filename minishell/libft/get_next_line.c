/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:05:15 by mickzhan          #+#    #+#             */
/*   Updated: 2025/12/05 10:30:15 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*new_get_line(char *str, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line = ft_calloc_line(sizeof(char), (i + 1));
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_line_free(char *str)
{
	int		i;
	int		j;
	char	*new_string;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	new_string = ft_calloc_line(sizeof(char), (ft_strlen(str) - i + 1));
	while (str[i])
		new_string[j++] = str[i++];
	new_string[j] = '\0';
	free(str);
	return (new_string);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*stock;
	char		*line;
	int			bytes_read;

	if (!stock)
		stock = ft_calloc_line(1, sizeof(char));
	line = NULL;
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stock, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (stock), stock = NULL, NULL);
		buffer[bytes_read] = '\0';
		stock = ft_strjoin_line(stock, buffer);
	}
	line = new_get_line(stock, line);
	if (ft_strchr(stock, '\n'))
		stock = get_line_free(stock);
	else
		(free(stock), stock = NULL);
	return (line);
}

// int	main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line;

// 	(void)ac;
// 	fd = open(av[1], O_RDONLY);
// 	__builtin_printf("FD |%d|\n", fd);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// }
