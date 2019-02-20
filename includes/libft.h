/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/02/19 17:04:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include "get_next_line.h"

# define FALSE	0
# define TRUE	1

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			**ft_lsttostrarr(const t_list *lst);
char			**ft_strarrnew(size_t size);
char			**ft_strdsplit(const char *s, const char *delims);
char			**ft_strfieldnew(int x, int y, char c);
char			**ft_strsplit(const char *s, char c);
char			*ft_chrtostr(char c);
char			*ft_itoa_base(long long value, int base);
char			*ft_itoa(long long value);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdtrim(const char *s, const char *delims);
char			*ft_strdup(const char *s);
char			*ft_strjoin_var(int count, ...);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strrchr(const char *s, int c);
char			*ft_strreplace(char **s1, const char *s2);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s);
int				*ft_lsttointarr(const t_list *lst);
int				ft_atoi_base(const char *s, int base);
int				ft_atoi(const char *s);
int				ft_chrdin(const char *s, char *c);
int				ft_chrin(const char *s, int c);
int				ft_chrindex(const char *s, int c);
int				ft_chrnin(const char *s, int c, size_t n);
int				ft_count_if(const char **s, int (*f)(char *));
int				ft_getchar(void);
int				ft_intin(const int *arr, int n, int len);
int				ft_intlen_base(int value, int base);
int				ft_intlen(int value);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isdigitstr(const char *s);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(char c);
int				ft_isupper(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_numlen_base(long long value, int base);
int				ft_numlen(long long value);
int				ft_puterror(const char *s);
int				ft_sqrt(int nb);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strin(const char **arr, const char *s);
int				ft_strmatch(const char *haystack, const char *needle);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_strnin(const char **arr, const char *s, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_uintlen_base(unsigned int value, int base);
int				ft_uintlen(unsigned int value);
int				ft_unumlen_base(unsigned long long value, int base);
int				ft_unumlen(unsigned long long value);
int				ft_wrddcount(const char *s, const char *delims);
long long		ft_abs(long long n);
long long		ft_constrain(long long n, long long num1, long long num2);
long long		ft_max(long long n1, long long n2);
long long		ft_min(long long n1, long long n2);
long long		ft_pow(long long n, long long pow);
size_t			ft_lstlen(const t_list *lst);
size_t			ft_strarrlen(const char **arr);
size_t			ft_strdlen(const char *s, const char *delims);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
size_t			ft_strnlen(const char *s, size_t n);
t_list			*ft_intarrtolst(const int *arr, int len);
t_list			*ft_lstdup(const t_list *lst);
t_list			*ft_lstdupone(const t_list *lst);
t_list			*ft_lstmap(const t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(const void *content, size_t content_size);
t_list			*ft_lstunlink(const t_list *head, const t_list *lst);
t_list			*ft_strarrtolst(const char **arr);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memdup(const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			ft_clearterminal(void);
void			ft_foreach(const int *arr, int length, void (*f)(int));
void			ft_lstadd(t_list **alst, const t_list *new);
void			ft_lstaddbck(const t_list *lst, const t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(const t_list *lst, void (*f)(t_list *elem));
void			ft_lstmemdel(void *s, size_t size);
void			ft_memdel(void **ap);
void			ft_putbool(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putendl(const char *s);
void			ft_putintarr(const int *tab, int len);
void			ft_putintlst(const t_list *lst);
void			ft_putline_fd(const char *s, int fd);
void			ft_putline(const char *s);
void			ft_putnbr_base(long long n, int base);
void			ft_putnbr_fd_base(long long value, int fd, int base);
void			ft_putnbr_fd(long long n, int fd);
void			ft_putnbr(long long n);
void			ft_putnstr_fd(const char *s, int fd, size_t n);
void			ft_putnstr(const char *s, size_t n);
void			ft_putpointer(const void *pointer);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putstr(const char *s);
void			ft_putstrarr(const char **arr);
void			ft_putstrlst(const t_list *lst);
void			ft_strappend(char **dst, const char *src);
void			ft_strarrdel(char ***arr);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(const char *s, void (*f)(char *));
void			ft_striteri(const char *s, void (*f)(unsigned int, char *));
void			ft_strrev(char *s);
void			ft_swap(int *a, int *b);
void			ft_tolowerstr(char *s);
void			ft_toupperstr(char *s);
char			*ft_strnstr(const char *haystack, const char *needle,
																	size_t len);

#endif
