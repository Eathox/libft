#include "char.h"

/*
** * Checks if c is a printable character including space
*/
bool ft_isprint(
	char c
) {
	return (c >= ' ' && c <= '~');
}
