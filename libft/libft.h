/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:39:49 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/25 17:53:48 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft_struct.h"

# define BUFF_SIZE 1024

/*
** Part one
*/
void		*ft_memset(void *s, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void		*ft_memmove(void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/*
** Part two
*/
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_itoa(int n);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*
** Part three
*/
t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Part custom
*/
char		*ft_rotx(const char *s, int x, char space);
char		*ft_revstr(char *s);
int			get_next_line_mfd(int const fd, char **line);
int			get_next_line(int const fd, char **line);
long int	ft_abs(long int i);
void		ft_tabdel(char ***tab);
size_t		ft_tablen(char **tab);
int			ft_strcount(const char *s1, const char *s2);
char		*ft_strreplace(char *s1, char *old, char *new);
char		*ft_strjoin_tw(const char *s1, const char *s2, const char *s3);
void		ft_skip_space(char **str);
uint32_t	ft_revint32(uint32_t nb);
uint64_t	ft_revint64(uint64_t nb);

/*
** Double linked lists
*/
t_dlst		*dlst_new(void);
t_dlst		*dlst_add_head(t_dlst *dl, long int ind, void *cont);
t_dlst		*dlst_add_tail(t_dlst *dl, long int ind, void *cont);
void		dlst_del(t_dlst **dl);

#endif
