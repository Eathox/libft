#include "char.h"

/*
** * Checks if c is a control character
*/
bool ft_iscntrl(
	char c
) {
	return (c <= 31 || c == 127);
}
