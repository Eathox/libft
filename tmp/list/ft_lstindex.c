#include "list.h"

t_list	*ft_lstindex(t_list *lst, size_t index) {
	while (lst != NULL && index > 0)
	{
		lst = lst->next;
		index--;
	}
	return (lst);
}
