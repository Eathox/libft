#include <unistd.h>

#include "str.h"

bool		ft_puterror(const char *str) {
	if (str == NULL)
		return (write(2, "(null)", 6) != -1);
	return (write(2, str, ft_strlen(str)) != -1);
}
