#include "list.h"

size_t		ft_lstnlen(const t_list *lst, size_t n) {
	size_t	len;

	len = 0;
	while (len < n && lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
