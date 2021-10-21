#include "../include/char.h"

bool ft_isspace(
	char c
) {
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
