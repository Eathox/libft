#include "../include/char.h"

/*
** * Checks if c is any of the following: ' ', '\t', '\n', '\v', '\f' or '\r'
*/
bool ft_isspace(
	char c
) {
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
