#include "list.h"

void	ft_lstaddbck(t_list **head, t_list *new) {
	t_list	*lst;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	lst = *head;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
}
