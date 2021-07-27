#include "../include/char.h"

/*
** * Checks if c is a upper or lower case letter
*/
bool ft_isalpha(
	char c
) {
	return (ft_islower(c) || ft_isupper(c));
}
