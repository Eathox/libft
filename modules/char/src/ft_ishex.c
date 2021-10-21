#include "../include/char.h"

bool ft_ishex(
	char c
) {
	c = ft_tolower(c);
	return (ft_isdigit(c) || (c >= 'a' && c <= 'f'));
}
