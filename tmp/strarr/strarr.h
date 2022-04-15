#ifndef FT_STRARR_H
#define FT_STRARR_H

#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#include "ft/list.h"

size_t ft_strarrlen(const char **arr);
size_t ft_strarrnlen(const char **arr, size_t n);
char **ft_strarrcpy_var(char **dst, size_t count, ...);
char **ft_strarrcpy(char **dst, const char **src);
char **ft_strarrdup_var(size_t count, ...);
char **ft_strarrdup(const char **arr);
char **ft_strarrnew(size_t size);
t_list *ft_strarrtolst(const char **arr);
void ft_strarrdel(char ***arr);
void ft_strarrrev(char **arr);
void ft_strarrtolower(char **arr);
void ft_strarrtoupper(char **arr);
bool ft_strarrsortac(const char *current, const char *str);
bool ft_putstrarr(const char **arr);
void ft_strarrsort(char **const arr, bool (*f)(const char *, const char *));
void ft_strarrsortrev(char **arr, bool (*f)(const char *, const char *));
void ft_strarrnsort(char **arr, bool (*f)(const char *, const char *), size_t n);
void ft_strarrnsortrev(char **arr, bool (*f)(const char *, const char *), size_t n);
char **ft_strfldnew(size_t x, size_t y, char c);
bool ft_strfldvalid(const char **arr, size_t x, size_t y, const char *dlm);

#endif
