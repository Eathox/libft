#include "ft/list.h"
#include "ft/num.h"

#include "numarr.h"

static t_list *freeret(t_list **lst) {
    ft_lstdel(lst, &ft_lstdelmem);
    return NULL;
}

t_list *ft_numarrtolst(const intmax_t *arr, size_t len) {
    t_list *returnlst;
    t_list *prvlst;
    t_list *newlst;
    intmax_t num;
    size_t i;

    i = 0;
    num = arr[i];
    returnlst = ft_lstnew_dup(&num, sizeof(intmax_t));
    if (returnlst == NULL)
        return NULL;
    prvlst = returnlst;
    while (i < len) {
        i++;
        num = arr[i];
        newlst = ft_lstnew_dup(&num, sizeof(intmax_t));
        if (newlst == NULL)
            return freeret(&returnlst);
        prvlst->next = newlst;
        prvlst = returnlst;
    }
    return returnlst;
}
