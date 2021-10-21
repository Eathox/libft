#include "../include/char.h"

bool ft_isprint(
	char c
) {
	return (c >= ' ' && c <= '~');
}
