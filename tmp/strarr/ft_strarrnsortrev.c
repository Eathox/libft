#include "strarr.h"

void ft_strarrnsortrev(char **arr, bool (*f)(const char *, const char *), size_t n) {
    size_t i;
    size_t j;
    char *current;

    i = 1;
    while (i < n && arr[i] != NULL) {
        j = i;
        current = arr[i];
        while (j > 0 &&
               f((const char *)current, (const char *)arr[j - 1]) == false) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = current;
        i++;
    }
}
