/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 23:47:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>


typedef struct s_list	t_list;

# ifndef BUFF_SIZE
#  define BUFF_SIZE 42
# endif

char			**ft_strdsplit(const char *str, const char *dlm);
char			**ft_strsplit(const char *str, char c);
char			*ft_strcat(char *str1, const char *str2);
char			*ft_strchr(const char *str, char c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdtrim(const char *str, const char *dlm);
char			*ft_strdup(const char *str);
char			*ft_strjoin_lst(t_list *lst);
char			*ft_strjoin_arr(const char **arr);
char			*ft_strjoin_var(size_t count, ...);
char			*ft_strjoin(const char *str1, const char *str2);
char			*ft_strmap(const char *str, char (*f)(char));
char			*ft_strmapi(const char *str, char (*f)(size_t, char));
char			*ft_strncat(char *str1, const char *str2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strndup(const char *str, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *str, const char *needle, size_t len);
char			*ft_strrchr(const char *str, char c);
char			*ft_strstr(const char *str, const char *needle);
char			*ft_strsub(const char *str, size_t start, size_t len);
char			*ft_strtolower(char *str);
char			*ft_strtoupper(char *str);
char			*ft_strtrim(const char *str);
bool			ft_strisdigit(const char *str);
bool			ft_strisfloat(const char *str);
bool			ft_strishex(const char *str);
bool			ft_strisempty(const char *str);
int				ft_strcmp_nocase(const char *str1, const char *str2);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp_nocase(const char *str1, const char *str2, size_t n);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
size_t			ft_strdlen(const char *str, const char *dlm);
size_t			ft_strislen(const char *str, bool (*f)(char));
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
size_t			ft_strmatchlen_nocase(const char *str1, const char *str2);
size_t			ft_strmatchlen(const char *str1, const char *str2);
size_t			ft_strnlen(const char *str, size_t n);
ssize_t			ft_strindex(const char **arr, const char *str);
ssize_t			ft_strnindex(const char **arr, const char *str, size_t n);
void			ft_strappend(char **dst, const char *src);
void			ft_strclr(char *str);
void			ft_strdel(char **as);
void			ft_striter(const char *str, void (*f)(const char *));
void			ft_striteri(const char *str, void (*f)(size_t, const char *));
void			ft_strrev(char *str);
bool			ft_strequ_nocase(const char *str1, const char *str2);
bool			ft_strequ(const char *str1, const char *str2);
bool			ft_strin(const char **arr, const char *str);
bool			ft_strmatch(const char *str, const char *needle);
bool			ft_strnequ_nocase(const char *str1, const char *str2, size_t n);
bool			ft_strnequ(const char *str1, const char *str2, size_t n);
bool			ft_strnin(const char **arr, const char *str, size_t n);
bool			ft_putendl_fd(const char *str, int fd);
bool			ft_putendl(const char *str);
bool			ft_puterror(const char *str);
bool			ft_putline_fd(const char *str, int fd);
bool			ft_putline(const char *str);
bool			ft_putnstr_fd(const char *str, size_t n, int fd);
bool			ft_putnstr(const char *str, size_t n);
bool			ft_putstr_fd(const char *str, int fd);
bool			ft_putstr(const char *str);
size_t			ft_wrddcount(const char *str, const char *dlm);
ssize_t			ft_getnextdline(int fd, char **line, char dlm);
ssize_t			ft_getnextline(int fd, char **line);
ssize_t			ft_readfile(int fd, char **str);
char			*ft_strformat(const char *format, ...);
char			*ft_strformat_len(size_t *len, const char *format, ...);
char			*ft_strreplace(const char *str, const char *find,
					const char *replace);

#endif
