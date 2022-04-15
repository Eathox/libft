#include "../include/char.h"

char ft_toupper(
    char c
) {
    if (c >= 'a' && c <= 'z')
        c -= ('a' - 'A');
    return c;
}
