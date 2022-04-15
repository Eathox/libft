#include "ft/str.h"

#include "strarr.h"

bool ft_strarrsortac(const char *current, const char *str) {
    int result;

    result = ft_strcmp(current, str);
    return (result < 0 && result != 0);
}
