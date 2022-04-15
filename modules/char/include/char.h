#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "types/include/types.h"

/*
** * Checks if c is either a lower/upper case letter or a number
*/
bool ft_isalnum(
    char c
);

/*
** * Checks if c is a upper or lower case letter
*/
bool ft_isalpha(
    char c
);

/*
** * Checks if c fits inside the ascii character set
*/
bool ft_isascii(
    char c
);

/*
** * Checks if c is a base 2 number character
*/
bool ft_isbinary(
    char c
);

/*
** * Checks if c is a space or tab
*/
bool ft_isblank(
    char c
);

/*
** * Checks if c is a control character
*/
bool ft_iscntrl(
    char c
);

/*
** * Checks if c is a number
*/
bool ft_isdigit(
    char c
);

/*
** * Checks if c is a printable character excluding space
*/
bool ft_isgraph(
    char c
);

/*
** * Checks if c is a base 16 number character, handles lower/upper case
*/
bool ft_ishex(
    char c
);

/*
** * Checks if c is a lowercase letter
*/
bool ft_islower(
    char c
);

/*
** * Checks if c is a base 8 number character
*/
bool ft_isoctal(
    char c
);

/*
** * Checks if c is a printable character including space
*/
bool ft_isprint(
    char c
);

/*
** * Checks if c is any of the following: ' ', '\t', '\n', '\v', '\f' or '\r'
*/
bool ft_isspace(
    char c
);

/*
** * Checks if c is a uppercase letter
*/
bool ft_isupper(
    char c
);

/*
** * If c is an uppercase letter return its lowercase equivalent
*/
char ft_tolower(
    char c
);

/*
** * If c is an lowercase letter return its uppercase equivalent
*/
char ft_toupper(
    char c
);
