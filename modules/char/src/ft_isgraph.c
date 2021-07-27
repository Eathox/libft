#include "../include/char.h"

/*
** * Checks if c is a printable character excluding space
*/
bool ft_isgraph(
	char c
) {
	return (c >= '!' && c <= '~');
}
