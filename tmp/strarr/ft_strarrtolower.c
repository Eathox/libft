#include "ft/str.h"

#include "strarr.h"

void ft_strarrtolower(char **arr) {
    size_t i;

    i = 0;
    while (arr[i] != NULL) {
        ft_strtolower(arr[i]);
        i++;
    }
}
