#include "ft/str.h"
#include "ft/strarr.h"

#include "list.h"

static char **freeret(char **arr) {
    free(arr);
    return NULL;
}

char **ft_lsttostrarr(t_list *lst) {
    t_list *current;
    char **arr;
    char *str;
    size_t i;
    size_t len;

    i = 0;
    len = ft_lstlen(lst);
    if (len == 0)
        return NULL;
    arr = ft_strarrnew(len);
    if (arr == NULL)
        return NULL;
    current = lst;
    while (current != NULL) {
        str = ft_strdup((char *)current->content);
        if (str == NULL)
            return freeret(arr);
        arr[i] = str;
        current = current->next;
        i++;
    }
    arr[i] = NULL;
    return arr;
}
