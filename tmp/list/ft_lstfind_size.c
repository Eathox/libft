#include "list.h"

t_list *ft_lstfind_size(t_list *lst, size_t size) {
    while (lst != NULL && lst->content_size != size)
        lst = lst->next;
    return lst;
}
