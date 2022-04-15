#include "list.h"

size_t ft_lstlen(const t_list *lst) {
    size_t len;

    len = 0;
    while (lst != NULL) {
        lst = lst->next;
        len++;
    }
    return len;
}
