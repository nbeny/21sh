/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:28:14 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/15 01:00:26 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "get_next_line.h"

typedef struct	s_lib
{
	void			*content;
	size_t			content_size;
	struct s_lib	*next;
}				t_lib;

size_t			ft_wstrlen(wchar_t *ws);
int				ft_wcharlen(wchar_t wchar);
size_t			ft_wbytelen(wchar_t *ws);
uintmax_t		ft_power(int n, int p);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, int start, int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
int				ft_putchar(int c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_max(int *tab, size_t n);
int				ft_min(int *tab, size_t n);
void			ft_sort_integer_tab(int *tab, int size);
void			ft_sort_params(int argc, char **argv);
int				ft_sqrt(int nb);
void			ft_putcstr(int c, int size);
void			ft_capitalizer(char *s);
char			*ft_rotcstring(char *s);
char			*ft_litoa_base(long int nb, int size);
char			*ft_llitoa_base(long long int nb, int size);
char			*ft_uitoa_base(unsigned int n, int size);
char			*ft_ulitoa_base(unsigned long int n, int size);
char			*ft_ullitoa_base(unsigned long long int nb, int size);
char			*ft_size_itoa_base(size_t n, int size);
char			*ft_max_itoa_base(intmax_t n, int size);
char			*ft_umax_itoa_base(uintmax_t n, int size);
char			*ft_short_itoa_base(short int n, int size);
char			*ft_ushort_itoa_base(unsigned short int n, int size);
char			*ft_char_itoa_base(signed char n, int size);
char			*ft_uchar_itoa_base(unsigned char n, int size);
int				ft_putnstr(char *s, size_t n);
void			ft_putnbr_base(int nb, char *base);
void			ft_uputnbr_base(unsigned int nb, char *base);
void			ft_char_putnbr_base(signed char nb, char *base);
void			ft_uchar_putnbr_base(unsigned char nb, char *base);
void			ft_lputnbr_base(long int nb, char *base);
void			ft_ulputnbr_base(unsigned long int nb, char *base);
void			ft_llputnbr_base(long long int nb, char *base);
void			ft_ullputnbr_base(unsigned long long int nb, char *base);
void			ft_max_putnbr_base(intmax_t nb, char *base);
void			ft_umax_putnbr_base(uintmax_t nb, char *base);
void			ft_size_putnbr_base(size_t nb, char *base);
t_lib			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_lib **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_lib **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_lib **alst, t_lib *new);
void			ft_lstiter(t_lib *lst, void (*f)(t_lib *elem));
t_lib			*ft_lstmap(t_lib *lst, t_lib *(*f)(t_lib *elem));
int				ft_space(char *s, int i);
int				ft_word(char *s, int i);
char			**ft_multisub(char **s, int start, int end);
int				ft_countstr(char **s, int c);
char			**ft_tabstr(char **s, int c);
int				ft_putnstr_fd(int fd, char *s, size_t n);
char			**ft_split(char const *s);
#endif
