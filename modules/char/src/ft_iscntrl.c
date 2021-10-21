#include "../include/char.h"

bool ft_iscntrl(
	char c
) {
	return (c <= 31 || c == 127);
}
