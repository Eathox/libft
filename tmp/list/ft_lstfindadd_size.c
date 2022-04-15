#include "list.h"

t_list *ft_lstfindadd_size(t_list *lst, size_t size) {
    t_list *newlst;

    while (lst != NULL && lst->next != NULL) {
        if (lst->content_size == size)
            return lst;
        lst = lst->next;
    }
    if (lst != NULL && lst->content_size == size)
        return lst;
    newlst = ft_lstnew(NULL, 0);
    if (newlst == NULL)
        return NULL;
    if (lst != NULL)
        lst->next = newlst;
    return newlst;
}
