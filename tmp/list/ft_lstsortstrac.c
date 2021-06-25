#include "ft/mem.h"

#include "list.h"

bool		ft_lstsortstrac(const t_list *sortlst, const t_list *lst) {
	int		result;
	size_t	n;

	n = sortlst->content_size;
	if (n < lst->content_size)
		n = lst->content_size;
	result = ft_memcmp(sortlst->content, lst->content, n);
	return (result > 0 && result != 0);
}
