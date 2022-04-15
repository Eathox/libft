#include "ft/mem.h"

#include "list.h"

t_list *ft_lstfind_content(t_list *lst, const void *content, size_t size) {
    while (lst != NULL && ft_memequ(lst->content, content, size) == false)
        lst = lst->next;
    return lst;
}
