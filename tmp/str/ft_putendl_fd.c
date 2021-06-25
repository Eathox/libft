#include "ft/char.h"

#include "str.h"

bool	ft_putendl_fd(const char *str, int fd) {
	if (ft_putstr_fd(str, fd) == false)
		return (false);
	return (ft_putchar_fd('\n', fd));
}
