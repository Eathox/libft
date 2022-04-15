#include "strarr.h"

void ft_strarrrev(char **arr) {
    size_t i;
    size_t len;
    size_t half;
    char *temp;

    i = 0;
    len = ft_strarrlen((const char **)arr);
    half = (len / 2);
    while (i < half) {
        temp = arr[i];
        arr[i] = arr[(len - 1) - i];
        arr[(len - 1) - i] = temp;
        i++;
    }
}
