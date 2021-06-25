#include "ft/mem.h"

#include "str.h"

void	ft_strclr(char *str) {
	ft_bzero(str, ft_strlen(str));
}
