#include "list.h"

static t_list	*freeret(t_list **lst) {
	ft_lstdel(lst, &ft_lstdelmem);
	return (NULL);
}

t_list			*ft_lstdup(const t_list *lst) {
	t_list	*current;
	t_list	*duplst;
	t_list	*prvlst;
	t_list	*retlst;

	retlst = ft_lstnew_dup(lst->content, lst->content_size);
	if (retlst == NULL)
		return (NULL);
	prvlst = retlst;
	current = lst->next;
	while (current != NULL)
	{
		duplst = ft_lstnew_dup(current->content, current->content_size);
		if (duplst == NULL)
			return (freeret(&retlst));
		prvlst->next = duplst;
		prvlst = duplst;
		current = current->next;
	}
	return (retlst);
}
