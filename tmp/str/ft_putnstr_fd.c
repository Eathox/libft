#include <unistd.h>

#include "str.h"

bool	ft_putnstr_fd(const char *str, size_t n, int fd) {
	if (str == NULL)
		return (write(fd, "(null)", n) != -1);
	return (write(fd, str, ft_strnlen(str, n)) != -1);
}
