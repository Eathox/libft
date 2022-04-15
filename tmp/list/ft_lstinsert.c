#include "list.h"

void ft_lstinsert(t_list *head, t_list *lst) {
    t_list *lstlast;

    lstlast = ft_lstlast(lst);
    lstlast->next = head->next;
    head->next = lst;
}
