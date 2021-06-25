#include "char.h"

/*
** * Checks if c is either a lower/upper case letter or a number
*/
bool ft_isalnum(
	char c
) {
	return (ft_isalpha(c) || ft_isdigit(c));
}
