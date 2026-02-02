/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickzhan <mickzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:09:52 by mickzhan          #+#    #+#             */
/*   Updated: 2026/01/23 10:12:28 by mickzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *ptr, size_t n);
void				*ft_calloc(size_t nitems, size_t size);
int					ft_isalnum(int character);
int					ft_isalpha(int character);
int					ft_isascii(int c);
int					ft_isdigit(int character);
int					ft_isprint(int character);
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_memchr(const void *memoryBlock, int searchedChar,
						size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				*ft_memcpy(void *destination, const void *source,
						size_t size);
void				*ft_memmove(void *destinaton, const void *source,
						size_t size);
void				*ft_memset(void *pointer, int value, size_t count);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int ch);
char				*ft_strdup(const char *str);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, char const *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t size);
char				*ft_strnstr(const char *str, const char *find, size_t size);
char				*ft_strrchr(const char *str, int chr);

char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int ch);
int					ft_toupper(int ch);

// GNL

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char				*get_next_line(int fd);
char				*get_line_free(char *str);
char				*new_get_line(char *str, char *line);
char				*ft_strcat_line(char *s1, char *s2, int size);
char				*ft_strjoin_line(char *s1, char *s2);
void				*ft_calloc_line(size_t nitems, size_t size);

// PRINTF

int					ft_printf(int fd, const char *format, ...);
int					ft_putchar(char c, int fd);
int					ft_putnbr(int nb, int fd);
int					ft_putstr(char *str, int fd);
unsigned int		ft_unsigned_putnbr(unsigned int nb, int fd);
unsigned int		ft_baselower16(unsigned int nb, int fd);
unsigned int		ft_baseupper16(unsigned int nb, int fd);
int					ft_pointer(void *p, int fd);
unsigned int		ft_div_intlen(unsigned long nb);
void				base_write16(unsigned int nb, int fd);

#endif