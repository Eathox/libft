#ifndef FT_UTF8_H
#define FT_UTF8_H

#include <stdbool.h>
#include <string.h>

typedef int t_wchar;

size_t ft_utf8len(t_wchar c);
size_t ft_utf8strlen(const t_wchar *str);
size_t ft_utf8strnlen(const t_wchar *str, size_t n);
bool ft_putnutf8str(const t_wchar *str, size_t n);
bool ft_putnutf8str_fd(const t_wchar *str, size_t n, int fd);
bool ft_pututf8_fd(t_wchar c, int fd);
bool ft_pututf8(t_wchar c);
bool ft_pututf8str(const t_wchar *str);
bool ft_pututf8str_fd(const t_wchar *str, int fd);

#endif
