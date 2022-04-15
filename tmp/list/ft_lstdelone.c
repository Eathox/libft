#include <stdlib.h>

#include "list.h"

void ft_lstdelone(t_list **head, void (*del)(void *, size_t)) {
    if (head == NULL || *head == NULL)
        return;
    if (del != NULL && (*head)->content != NULL)
        del((*head)->content, (*head)->content_size);
    free(*head);
    *head = NULL;
}
