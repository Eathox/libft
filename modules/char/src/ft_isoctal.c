#include "../include/char.h"

/*
** * Checks if c is a base 8 number character
*/
bool ft_isoctal(
	char c
) {
	return (c >= '0' && c <= '7');
}
