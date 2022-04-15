#include "ft/mem.h"

#include "list.h"

static t_list *freeret(t_list *lst) {
    free(lst);
    return NULL;
}

t_list *ft_lstnew_dup(const void *content, size_t content_size) {
    t_list *lst;

    lst = (t_list *)ft_memalloc(sizeof(t_list));
    if (lst == NULL)
        return NULL;
    if (content != NULL) {
        lst->content = ft_memdup(content, content_size);
        if (lst->content == NULL)
            return freeret(lst);
        lst->content_size = content_size;
    }
    return lst;
}
