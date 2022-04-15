#include "list.h"

void ft_lstdel(t_list **head, void (*del)(void *, size_t)) {
    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next != NULL)
        ft_lstdel(&(*head)->next, del);
    ft_lstdelone(head, del);
}
