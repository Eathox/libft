#include "ft/str.h"

#include "strarr.h"

bool ft_putstrarr(const char **arr) {
    size_t i;

    i = 0;
    if (arr == NULL)
        return ft_putstr(NULL);
    while (arr[i] != NULL) {
        if (ft_putendl(arr[i]) == false)
            return false;
        i++;
    }
    return true;
}
