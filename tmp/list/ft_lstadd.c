#include "list.h"

void	ft_lstadd(t_list **head, t_list *new) {
	new->next = *head;
	*head = new;
}
