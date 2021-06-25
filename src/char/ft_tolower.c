#include "char.h"

/*
** * If c is an uppercase letter return its lowercase equivalent
*/
char ft_tolower(
	char c
) {
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}
