#include "../include/char.h"

char ft_tolower(
    char c
) {
    if (c >= 'A' && c <= 'Z')
        c += ('a' - 'A');
    return c;
}
