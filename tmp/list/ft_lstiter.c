#include "list.h"

void	ft_lstiter(const t_list *lst, void (*f)(const t_list *elem)) {
	f(lst);
	if (lst->next != NULL)
		ft_lstiter(lst->next, f);
}
