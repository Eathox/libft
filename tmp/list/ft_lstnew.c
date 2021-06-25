#include "ft/mem.h"

#include "list.h"

t_list			*ft_lstnew(void *content, size_t content_size) {
	t_list	*lst;

	lst = (t_list *)ft_memalloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->content_size = content_size;
	return (lst);
}
