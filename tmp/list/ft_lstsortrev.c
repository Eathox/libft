#include "list.h"

static t_list	*join(t_list *head, t_list *half,
					bool (*f)(const t_list *, const t_list *)) {
	if (head == NULL)
		return (half);
	if (half == NULL)
		return (head);
	if (f(head, half) == false)
	{
		half->next = join(head, half->next, f);
		return (half);
	}
	head->next = join(head->next, half, f);
	return (head);
}

void			ft_lstsortrev(t_list **head,
					bool (*f)(const t_list *, const t_list *)) {
	t_list	*half;
	t_list	*temp;

	if ((*head)->next == NULL)
		return ;
	temp = ft_lstindex(*head, (ft_lstlen(*head) - 1) / 2);
	half = temp->next;
	temp->next = NULL;
	ft_lstsortrev(head, f);
	ft_lstsortrev(&half, f);
	*head = join(*head, half, f);
}
