#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

ssize_t			ft_printf(const char *format, ...);
ssize_t			ft_dprintf(int fd, const char *format, ...);
char			*ft_strformat(const char *format, ...);
char			*ft_strformat_len(size_t *len, const char *format, ...);

#endif
