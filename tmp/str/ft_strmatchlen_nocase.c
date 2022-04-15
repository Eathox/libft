#include "ft/char.h"

#include "str.h"

size_t ft_strmatchlen_nocase(const char *str1, const char *str2) {
    size_t i;
    unsigned char temp_a;
    unsigned char temp_b;

    i = 0;
    if (str1 == NULL || str2 == NULL)
        return 0;
    temp_a = ft_tolower(str1[i]);
    while (temp_a != '\0') {
        temp_b = ft_tolower(str2[i]);
        if (temp_a != temp_b)
            return i;
        i++;
    }
    return i;
}
