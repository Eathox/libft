#include "ft/str.h"

#include "list.h"

bool	ft_putstrlst(const t_list *lst) {
	if (lst == NULL)
		return (ft_putstr(NULL));
	if (ft_putendl((char *)lst->content) == false)
		return (false);
	if (lst->next != NULL)
		return (ft_putstrlst(lst->next));
	return (false);
}
