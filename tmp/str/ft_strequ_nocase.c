#include "str.h"

bool ft_strequ_nocase(const char *str1, const char *str2) {
    return (ft_strcmp_nocase(str1, str2) == 0);
}
