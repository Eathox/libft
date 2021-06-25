#include <unistd.h>

#include "str.h"

bool	ft_putstr_fd(const char *str, int fd) {
	if (str == NULL)
		return (write(fd, "(null)", 6) != -1);
	return (write(fd, str, ft_strlen(str)) != -1);
}
