#include "char.h"

/*
** * Checks if c is a base 16 number character, handles lower/upper case
*/
bool ft_ishex(
	char c
) {
	c = ft_tolower(c);
	return (ft_isdigit(c) || (c >= 'a' && c <= 'f'));
}
