/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:04:46 by aohssine          #+#    #+#             */
/*   Updated: 2024/09/22 18:22:58 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "./../../includes/minishell.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_split
{
	int	i;
	int	j;
	int	k;
}	t_split;

char				*ft_strcat(char *dest, char *src);
char				*ft_strcpy(char *dest, char *src);
int     			ft_strcmp(char *s1, char *s2);
void 				free_split(char **str);
int 				ft_strslen(char **strs);
char 				**ft_strsdup(char **base);
char				*ft_strndup(const char *s1, size_t size);
char				*ft_strnmdup(const char *s1, size_t n, size_t m);
void				*ft_memset(void *b, int c, size_t len);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				ft_bzero(void *s, size_t len);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int     			ft_strcmp(char *s1, char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
						unsigned int len);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char  *s1, char const *s2);
char				*ft_strjoin_pro(char *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, 
						void *(*f)(void *), void (*del)(void *));

#endif