#include "char.h"

/*
** * If c is an lowercase letter return its uppercase equivalent
*/
char ft_toupper(
	char c
) {
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
	return (c);
}
