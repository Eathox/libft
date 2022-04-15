#include "list.h"

void ft_lstrev(t_list **head) {
    t_list *lst;
    t_list *prvlst;
    t_list *nxtlst;

    lst = *head;
    prvlst = NULL;
    while (lst != NULL) {
        nxtlst = lst->next;
        lst->next = prvlst;
        prvlst = lst;
        lst = nxtlst;
    }
    *head = prvlst;
}
