#include "ft/str.h"
#include "ft/num.h"
#include "ft/char.h"

#include "list.h"

bool	ft_putlstsize(const t_list *lst) {
	if (lst == NULL)
		return (ft_putstr(NULL));
	if (ft_putnum(lst->content_size) == false)
		return (false);
	if (ft_putchar('\n') == false)
		return (false);
	if (lst->next != NULL)
		return (ft_putlstsize(lst->next));
	return (true);
}
