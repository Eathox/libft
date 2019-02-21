/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/02/21 16:51:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include "get_next_line.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

# define FALSE	0
# define TRUE	1

char			**ft_lsttostrarr(t_list *lst);
char			**ft_strarrnew(size_t size);
char			**ft_strdsplit(const char *str, const char *delims);
char			**ft_strfieldnew(int x, int y, char c);
char			**ft_strsplit(const char *str, char c);
char			*ft_chrtostr(char c);
char			*ft_itoa_base(long long value, int base);
char			*ft_itoa(long long value);
char			*ft_strcat(char *str1, const char *str2);
char			*ft_strchr(const char *str, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdtrim(const char *str, const char *delims);
char			*ft_strdup(const char *str);
char			*ft_strjoin_var(int count, ...);
char			*ft_strjoin(const char *str1, const char *str2);
char			*ft_strmap(const char *str, char (*f)(char));
char			*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char			*ft_strncat(char *str1, const char *str2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strndup(const char *str, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *str, const char *needle, size_t len);
char			*ft_strrchr(const char *str, int c);
char			*ft_strreplace(char **str1, const char *str2);
char			*ft_strstr(const char *str, const char *needle);
char			*ft_strsub(const char *str, unsigned int start, size_t len);
char			*ft_strtrim(const char *str);
int				*ft_lsttointarr(t_list *lst);
int				ft_atoi_base(const char *str, int base);
int				ft_atoi(const char *str);
int				ft_chrdin(const char *str, const char *delims);
int				ft_chrdindex(const char *str, const char *delims);
int				ft_chrin(const char *str, int c);
int				ft_chrindex(const char *str, int c);
int				ft_chrnin(const char *str, int c, size_t n);
int				ft_count_if(const char **str, int (*f)(char *));
int				ft_getchar(void);
int				ft_intin(const int *arr, int n, int len);
int				ft_intlen_base(int value, int base);
int				ft_intlen(int value);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isdigitstr(const char *str);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(char c);
int				ft_isupper(int c);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
int				ft_numlen_base(long long value, int base);
int				ft_numlen(long long value);
int				ft_puterror(const char *str);
int				ft_sqrt(int nb);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strequ(const char *str1, const char *str2);
int				ft_strin(const char **arr, const char *str);
int				ft_strmatch(const char *str, const char *needle);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_strnequ(const char *str1, const char *str2, size_t n);
int				ft_strnin(const char **arr, const char *str, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_uintlen_base(unsigned int value, int base);
int				ft_uintlen(unsigned int value);
int				ft_unumlen_base(unsigned long long value, int base);
int				ft_unumlen(unsigned long long value);
int				ft_wrddcount(const char *str, const char *delims);
long long		ft_abs(long long num);
long long		ft_constrain(long long strain, long long num1, long long num2);
long long		ft_max(long long num1, long long num2);
long long		ft_min(long long num1, long long num2);
long long		ft_pow(long long num, long long pow);
size_t			ft_lstlen(t_list *lst);
size_t			ft_strarrlen(const char **arr);
size_t			ft_strdlen(const char *str, const char *delims);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
size_t			ft_strnlen(const char *str, size_t n);
t_list			*ft_intarrtolst(const int *arr, int len);
t_list			*ft_lstdup(t_list *lst);
t_list			*ft_lstdupone(t_list *lst);
t_list			*ft_lstfind_content(t_list *lst, void *content);
t_list			*ft_lstfind_size(t_list *lst, size_t size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(const void *content, size_t content_size);
t_list			*ft_lstunlink(t_list *head, t_list *lst);
t_list			*ft_strarrtolst(const char **arr);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memdup(const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memrcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *str, int c, size_t len);
void			ft_bzero(void *str, size_t n);
void			ft_clearterminal(void);
void			ft_foreach(const int *arr, int length, void (*f)(int));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstaddbck(t_list *lst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstmemdel(void *str, size_t size);
void			ft_memdel(void **ap);
void			ft_putbool(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putendl(const char *str);
void			ft_putintarr(const int *arr, int len);
void			ft_putintlst(t_list *lst);
void			ft_putline_fd(const char *str, int fd);
void			ft_putline(const char *str);
void			ft_putnbr_base(long long value, int base);
void			ft_putnbr_cbase(long long value, int base, int up);
void			ft_putnbr_fd_base(long long value, int fd, int base);
void			ft_putnbr_fd_cbase(long long value, int fd, int base, int up);
void			ft_putnbr_fd(long long value, int fd);
void			ft_putnbr(long long value);
void			ft_putnstr_fd(const char *str, int fd, size_t n);
void			ft_putnstr(const char *str, size_t n);
void			ft_putpointer(const void *pointer);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putstr(const char *str);
void			ft_putstrarr(const char **arr);
void			ft_putstrlst(t_list *lst);
void			ft_strappend(char **dst, const char *src);
void			ft_strarrdel(char ***arr);
void			ft_strclr(char *str);
void			ft_strdel(char **as);
void			ft_striter(const char *str, void (*f)(char *));
void			ft_striteri(const char *str, void (*f)(unsigned int, char *));
void			ft_strrev(char *str);
void			ft_swap(int *a, int *b);
void			ft_tolowerstr(char *str);
void			ft_toupperstr(char *str);

#endif
