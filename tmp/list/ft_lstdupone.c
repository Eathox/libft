#include "list.h"

t_list *ft_lstdupone(const t_list *lst) {
    t_list *duplst;

    duplst = ft_lstnew_dup(lst->content, lst->content_size);
    if (duplst == NULL)
        return NULL;
    return duplst;
}
