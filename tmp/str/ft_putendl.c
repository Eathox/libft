#include "str.h"

bool	ft_putendl(const char *str) {
	return (ft_putendl_fd(str, 1));
}
